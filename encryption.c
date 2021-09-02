#ifdef _WIN32
#pragma comment(lib, "xxtea.lib")
#endif

#include <stdio.h>
#include <string.h>
#include "xxtea.c"
#include "base64.c"
#include "xxtea.h"
#include "base64.h"

int main() {
    //const char *text = "{\"a\":1,\"b\":2,\"c\":[\"data\",1,[\"data\"],{\"obcc\":\"data\"}],\"d\":[\"data\",1,[\"data\"]],\"e\":[\"data\",1,[\"data\"]],\"data\":[\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\",\"data\"]}";
    const char *text ="24525825547fgrgrthrt@#$%%^fgjhjtfjuufygjyt";
    const char *key = "comtron@01012021";
    size_t len;
    printf("Plain text\n");
    printf("\n%s\n",text);

    printf("====================================================================================================================================================================================");
    printf("\nXXTEA encoded data \n");
    printf("====================================================================================================================================================================================");
   
    unsigned char *encrypt_data = xxtea_encrypt(text, strlen(text), key, &len);
    printf("\n%s\n", encrypt_data);
   
    printf("====================================================================================================================================================================================");
    printf("\nBase64 encoded data \n");
    printf("====================================================================================================================================================================================");
   
    char * base64_data = base64_encode(encrypt_data, len);
    printf("\n%s\n", base64_data);

                //char * base64_data="oTnh74mmIa0FOGwXWldPCefDCeUnk8ILCkGVHCJO2pSTXebQ4JRTIIBXcqn++FWkDMAy+6keqwrYC8A0KNcqvat0s1U+0iA2oP3LVRtgN6o9+ceI1/surFOmj0H3IC4c2WUL7A==";
    printf("====================================================================================================================================================================================");
    printf("\nBase64 decoded data \n");
    printf("====================================================================================================================================================================================");
   
    unsigned char * base64_ddata=base64_decode((const char * )base64_data,&len);
    printf("\n%s\n", base64_ddata);
    
    printf("====================================================================================================================================================================================");
    printf("\nXXTEA decoded data\n");
    printf("====================================================================================================================================================================================");
   
    char * decrypt_data = xxtea_decrypt(base64_ddata, len, key, &len);
    printf("\n%s\n", decrypt_data);

    free(encrypt_data);
    free(decrypt_data);
    free(base64_data);
    free(base64_ddata);
    return (0); 
}