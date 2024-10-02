/*
 * CALCULATOR_Prog.c
 *
 * Created: 2/7/2024 9:43:08 PM
 *  Author: Magic
 */ 


#include "StdTypes.h"
#include "LCD_Int.h"
#include "KEYPAD_Int.h"

static u8 Store_operations (s32* arr,u8 operation,u8 ind,s32 num) // true
{
	arr[ind]=num;
	ind++;
	arr[ind]=operation;
	ind++;
	
	return ind;
}

static void shift_data (s32* DataArr,u8 ind)
{
	while((ind+2) != ('=') )
	{
		DataArr[ind]=DataArr[ind+2];
		ind++;
	}
	DataArr[ind]=DataArr[ind+2];
	return;
}

static u32 Calc_Result (s32* DataArr,u8 ind,u8 flag_prod_div,u8 flag_add_sub)
{
	u8 i=0;
	s32 result=0;
	while(DataArr[i]!='=' && flag_prod_div!='0' && i<ind)
	{
		if(DataArr[i]=='*')
		{
			DataArr[i-1]=DataArr[i-1]*DataArr[i+1];
			shift_data(DataArr,i);
			flag_prod_div--;
			i--;
		}
		else if(DataArr[i]=='/')
		{
			DataArr[i-1]=DataArr[i-1]/DataArr[i+1];
			shift_data(DataArr,i);
			flag_prod_div--;
			i--;
		}
		i++;
	}
	i=0;
	while(DataArr[i]!='=' && flag_add_sub!='0' && i<ind)
	{
		if(DataArr[i]=='+')
		{
			DataArr[i-1]=DataArr[i-1]+DataArr[i+1];
			shift_data(DataArr,i);
			flag_add_sub--;
			i--;
		}
		else if(DataArr[i]=='-')
		{
			DataArr[i-1]=DataArr[i-1]-DataArr[i+1];
			shift_data(DataArr,i);
			flag_add_sub--;
			i--;
		}
		i++;
	}
	result=DataArr[0];
	
	for(i=0;i<ind;i++)
	{
		DataArr[i]=0;
	}
	
	return result;
}

static u8 Num_Of_Digit (u32 num)
{
	u8 digits=0;
	while(num)
	{
		num=num/10;
		digits++;
	}
	return digits;
}

static u8 string_len(u8 *str)
{
	int i;
	for(i=0;str[i];i++);
	return i;
}

static void string_reverse(u8 *str)
{
	u8 i=0,j=string_len(str)-1;
	s8 temp;
	for(;i<=j;)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	
}

static void int_to_str (u32 result, u8* str)
{
	u8 i=0;
	u32 remainder=10,div=1;
	u8 digits=Num_Of_Digit(result);
	for(i=0;i<digits;i++)
	{
		str[i]=(((result%remainder)/div)+'0');
		remainder=remainder*10;
		div=div*10;
	}
	str[i]=0;
	string_reverse(str);
	return;
}


void Calc_Runnable (void)
{
	//Welcome();
	
	u8 k,flag_prod_div=0,flag_add_sub=0, str[20];
	s32 num=0,result;
	u8 flag_start=0,ind=0;
	s32 arr[20];
	
	
	LCD_SetCursor(1,1);
	while (1)
	{
		k=KEYPAD_GetKey();
		if (k!=NO_KEY)
		{
			if(k>='0'&&k<='9')
			{
				if (flag_start==0)
				{
					LCD_Clear();
					LCD_SetCursor(1,1);
					LCD_WriteString("          ");
					LCD_SetCursor(1,1);
					flag_start=1;
				}
				
				num=num*10+k-'0';
				LCD_WriteChar(k);
			}
			switch (k)
			{
				case '*' :
				LCD_WriteChar(k);
				ind=Store_operations(arr,'*',ind,num);
				flag_prod_div++;
				num=0;
				break;
				
				case '/' :
				LCD_WriteChar(k);
				ind=Store_operations(arr,'/',ind,num);
				flag_prod_div++;
				num=0;
				break;
				
				case '+' :
				LCD_WriteChar(k);
				ind=Store_operations(arr,'+',ind,num);
				flag_add_sub++;
				num=0;
				break;
				
				case '-' :
				LCD_WriteChar(k);
				ind=Store_operations(arr,'-',ind,num);
				flag_add_sub++;
				num=0;
				break;
				
				case '=' :
				LCD_WriteChar(k);
				ind=Store_operations(arr,'=',ind,num);
				num=0;
				
				result=Calc_Result(arr,ind,flag_prod_div,flag_add_sub);
				int_to_str(result,str);
				
				LCD_SetCursor(2,1);
				LCD_WriteString(str);
				
				for(s8 j=0;j<=ind;j++)
				{
					str[j]=0;
				}
				for(s8 j=0;j<ind;j++)
				{
					arr[j]=0;
				}
				ind=0;
				flag_add_sub=0;
				flag_prod_div=0;
				flag_start=0;
				break;
				
				case 'c' :
				LCD_Clear();
				
				flag_add_sub=0;
				flag_prod_div=0;
				flag_start=0;
				result=0;
				num=0;
				
				for(s8 j=0;j<ind;j++)
				{
					arr[j]=0;
				}
				ind=0;
				break;
			}
			
			
		}
		
	}
}