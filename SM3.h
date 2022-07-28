#ifndef _SM3_H_
#define _SM3_H_
 
#define SM3_HASH_SIZE 32    //SM3算法产生的哈希值大小

//上下文
typedef struct SM3Context
{
	unsigned int intermediateHash[SM3_HASH_SIZE / 4];
	unsigned char messageBlock[64];
} SM3Context;
 
//计算函数
unsigned char *SM3Calc(const unsigned char *message,
	unsigned int messageLen, unsigned char digest[SM3_HASH_SIZE]);
 
#endif // _SM3_H_
