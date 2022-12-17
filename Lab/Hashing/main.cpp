/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Hashing Functions pulled from:
 * http://www.partow.net/programming/hashfunctions/#RSHashFunction
 * 
 * Created on November 16, 2022, 6:45 PM
 */

#include <iostream>
#include <string>

using namespace std;

unsigned int RSHash(const char*, unsigned int);
unsigned int JSHash(const char*, unsigned int);
unsigned int PJWHash(const char*, unsigned int);
unsigned int ELFHash(const char*, unsigned int);
unsigned int BKDRHash(const char*, unsigned int);
unsigned int SDBMHash(const char*, unsigned int);
unsigned int DJBHash(const char*, unsigned int);
unsigned int DEKHash(const char*, unsigned int);
unsigned int BPHash(const char*, unsigned int);
unsigned int FNVHash(const char*, unsigned int);
unsigned int APHash(const char*, unsigned int);

int main(int argc, char** argv) 
{
    const char* key = "Then out spake brave Horatius,\nThe Captain of the Gate:\n"
            "To every man upon this earth\nDeath cometh soon or late.\nAnd "
            "how can man die better\nThan facing fearful odds,\nFor the "
            "ashes of his fathers,\nAnd the temples of his gods.";
    int length=0;
    while(key[length] != '\0') length++;
    cout<<"Key: \n"<<key<<endl;
    cout<<"1. RSHash: "<<RSHash(key,length)<<endl;
    cout<<"2. JSHash: "<<JSHash(key,length)<<endl;
    cout<<"3. PJWHash: "<<PJWHash(key,length)<<endl;
    cout<<"4. ELFHash: "<<ELFHash(key,length)<<endl;
    cout<<"5. BKDRHash: "<<BKDRHash(key,length)<<endl;
    cout<<"6. SDBMHash: "<<SDBMHash(key,length)<<endl;
    cout<<"7. DJBHash: "<<DJBHash(key,length)<<endl;
    cout<<"8. DEKHash: "<<DEKHash(key,length)<<endl;
    cout<<"9. BPHash: "<<BPHash(key,length)<<endl;
    cout<<"10. FNVHash: "<<FNVHash(key,length)<<endl;
    cout<<"11. APHash: "<<APHash(key,length);
    
    return 0;
}

unsigned int RSHash(const char* str, unsigned int length)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = hash * a + (*str);
      a    = a * b;
   }

   return hash;
}

unsigned int JSHash(const char* str, unsigned int length)
{
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash ^= ((hash << 5) + (*str) + (hash >> 2));
   }

   return hash;
}

unsigned int PJWHash(const char* str, unsigned int length)
{
   const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   const unsigned int HighBits          =
                      (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash = 0;
   unsigned int test = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash << OneEighth) + (*str);

      if ((test = hash & HighBits) != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}

unsigned int ELFHash(const char* str, unsigned int length)
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash << 4) + (*str);

      if ((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }

      hash &= ~x;
   }

   return hash;
}

unsigned int BKDRHash(const char* str, unsigned int length)
{
   unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash * seed) + (*str);
   }

   return hash;
}

unsigned int SDBMHash(const char* str, unsigned int length)
{
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (*str) + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}

unsigned int DJBHash(const char* str, unsigned int length)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = ((hash << 5) + hash) + (*str);
   }

   return hash;
}

unsigned int DEKHash(const char* str, unsigned int length)
{
   unsigned int hash = length;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
   }

   return hash;
}

unsigned int BPHash(const char* str, unsigned int length)
{
   unsigned int i    = 0;
   unsigned int hash = 0;
   
   for(i = 0; i < length; i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}

unsigned int FNVHash(const char* str, unsigned int length)
{
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   unsigned int i    = 0;
   
   for(i = 0; i < length; i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}

unsigned int APHash(const char* str, unsigned int length)
{
   unsigned int hash = 0xAAAAAAAA;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*str) * (hash >> 3)) :
                               (~((hash << 11) + ((*str) ^ (hash >> 5))));
   }

   return hash;
}