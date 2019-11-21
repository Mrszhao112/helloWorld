1.实现strcpy
Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).
源字符串必须以 ‘\0’ 结束。
会将源字符串中的 ‘\0’ 拷贝到目标空间。
目标空间必须足够大，以确保能存放源字符串。
目标空间必须可变
char* myStrcpy(char* dest,const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	
	while ((*dest++=*src++))
	{
		;
	}
	return ret;
}
2.实现strcat
Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the ﬁrst character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.
源字符串必须以 ‘\0’ 结束。
目标空间必须有足够的大，能容纳下源字符串的内容。
目标空间必须可修改
char* myStrcat(char* dest,const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest++=*src++))
	{
		;
	}
	return ret;
}

3.实现strstr
这个函数用于判断两个字符串是否一个是另一个的字串
如果不是返回null
char* myStrstr(const char* str1,const char* str2)
{
	assert(str1);
	assert(str2);
	char* cp = (char*)str1;
	char* substr = (char*)str2;
	char* s1 = NULL;
	if (str2=='\0')
	{
		return NULL;
	}
	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1&&*substr&&(*s1==*substr))
		{
			s1++;
			substr++;
		}
		if (substr=='\0')
			return cp;
		cp++;
	}	
}
4.实现strchr
该函数用来寻找目标字符串中是否有我们所寻找的字符
char* myStrchr(const char* dest, char c)
{
	assert(dest);
	while (dest)
	{
		if (*dest==c)
		{
			return dest;
		}
		dest++;
	}
	return NULL;
}

5.实现strcmp
比较从ptr1和ptr2指针开始的num个字节
标准规定： 第一个字符串大于第二个字符串，则返回大于0的数字 第一个字符串等于第二个字符串，则返回0 第一个字符串小于第二个字符串，则返回小于0的数
int myStrcmp(const char* str1,const char* str2)
{
	int ret = 0; 
	assert(str1 != NULL);    
	assert(str2 != NULL);       
	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str2)
	{
		++str1, ++str2;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return(ret);
}

