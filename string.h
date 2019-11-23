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
6.实现memcpy
函数memcpy从source的位置开始
向后复制num个字节的数据到destination的内存位置。
这个函数在遇到 ‘\0’ 的时候并不会停下来。
如果source和destination有任何的重叠，复制的结果都是未定义的
void* myMemcpy(void* dst,const void* src,size_t num)
{
	assert(dst&&src);
	char* strSrc = (char*)src;
	char* strDst = (char*)dst;
	while (num)
	{
		*strDst= *strSrc;
		
		strDst++;
		strSrc++;
		num--;
	}
	return dst;
}
7.实现memmove
和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
如果源空间和目标空间出现重叠，就得使用memmove函数处理
`void* myMemove(void* dst,const void* src,size_t num)
{
	assert(dst&&src);
	char* strDst = (char*)dst;
	char* strSrc = (char*)src;
	//分为前重叠和后重叠
	if (strDst<strSrc&&(strDst+num)>strSrc)
	{
		while (num)
		{
			*strDst = *strSrc;
			num--;
			strSrc++;
			strDst++;
		}
	} 
	else if(strSrc<strDst&&strSrc+num>strDst)
	{
		while (num)
		{
			*(strDst + num) = *(strSrc + num);
			num--;
		}
	}
	else
	{
		while (num)
		{
			*strDst = *strSrc;
			num--;
			strSrc++;
			strDst++;
		}
	}
	return dst;
}
8.实现strncpy
Copies the ﬁrst num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.
拷贝num个字符从源字符串到目标空间。
如果源字符串的长度小于num，
则拷贝完源字符串之后，在目标的后边追加0，直到num个
char* myStrncpy(char* dest, const char* src, size_t num)
{
	assert(dest&&src);
	char* ret = dest;
	num--;
	while ((*dest++ = *src++) && (num--))
	{
		;
	}
	return ret;
}

9.实现strncat
Appends the ﬁrst num characters of source to destination, plus a terminating null-character. If the length of the C string in source is less than num, only the content up to the terminating nullcharacter is copied.
char* myStrncat(char*dest, const char*src, size_t num)
{
	assert(dest&&src);
	char* ret = dest;
	while (*++dest);

	while (src&&num)
	{
		*dest++ = *src++;
		num--;
	}
	return ret;
}
10.实现strncmp

比较到出现另个字符不一样或者一个字符串结束或者num个字符全部比较完
int myStrncmp(const char* dest, const char* src, size_t num)
{
	assert(dest&&src);
	while (dest++&&src++&&num--)
	{
		if (*dest > *src)
		{
			return 1;
		}
		if (*dest < *src)
		{
			return -1;
		}
	}
	return 0;
}
