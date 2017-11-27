/*
	Lauren Marsillo 500689959
	Michael Gorokhovsky 500681974
*/

#include <stdio.h>
#define atoa(x) #x
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void f(unsigned int *RightStart,int key[], int out[6])
{
	
	unsigned int afterExpansion[8];
	int sBox11[8] = {101, 010, 001, 110, 011, 100, 111, 000};
	int sBox12[8] = {001, 100, 110, 010, 000, 111, 101, 011};
	int sBox21[8] = {100, 000, 110, 101, 111, 001, 011, 010};
	int sBox22[8] = {101, 011, 000, 111, 110, 010, 001, 100};
	
	afterExpansion[0] = RightStart[0];
	afterExpansion[1] = RightStart[1];
	afterExpansion[2] = RightStart[3];
	afterExpansion[3] = RightStart[2];
	afterExpansion[4] = RightStart[3];
	afterExpansion[5] = RightStart[2];
	afterExpansion[6] = RightStart[4];
	afterExpansion[7] = RightStart[5];

	//XORing binary values with key
	int postXOR[8];
	for (int a = 0; a < 8; a++)
	{
		postXOR[a] = key[a] ^ afterExpansion[a];
		
	}
	
	//Now we must split the key into two 4-bit parts.
	int FirstFourBits[4];
	int SecondFourBits[4];
	FirstFourBits[0] = postXOR[0];
	FirstFourBits[1] = postXOR[1];
	FirstFourBits[2] = postXOR[2];
	FirstFourBits[3] = postXOR[3];
	SecondFourBits[0] = postXOR[4];
	SecondFourBits[1] = postXOR[5];
	SecondFourBits[2] = postXOR[6];
	SecondFourBits[3] = postXOR[7];
	
	//And now they are inputed into the s-boxes
	int sBox1Out;
	int sBox2Out;
	if (FirstFourBits[0] == 0)
	{
		if (FirstFourBits[1] == 0 && FirstFourBits[2] == 0 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox11[0];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 0 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox11[1];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 1 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox11[2];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 1 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox11[3];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 0 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox11[4];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 0 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox11[5];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 1 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox11[6];
		}
		else 
			sBox1Out = sBox11[7];
	}
	else
	{
		if (FirstFourBits[1] == 0 && FirstFourBits[2] == 0 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox12[0];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 0 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox12[1];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 1 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox12[2];
		}
		else if (FirstFourBits[1] == 0 && FirstFourBits[2] == 1 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox12[3];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 0 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox12[4];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 0 && FirstFourBits[3] == 1)
		{
			sBox1Out = sBox12[5];
		}
		else if (FirstFourBits[1] == 1 && FirstFourBits[2] == 1 && FirstFourBits[3] == 0)
		{
			sBox1Out = sBox12[6];
		}
		else 
			sBox1Out = sBox12[7];
	}
	//now for s-box 2
		if (SecondFourBits[0] == 0)
	{
		if (SecondFourBits[1] == 0 && SecondFourBits[2] == 0 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox21[0];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 0 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox21[1];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 1 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox21[2];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 1 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox21[3];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 0 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox21[4];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 0 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox21[5];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 1 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox21[6];
		}
		else 
			sBox2Out = sBox21[7];
	}
	else
	{
		if (SecondFourBits[1] == 0 && SecondFourBits[2] == 0 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox22[0];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 0 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox22[1];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 1 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox22[2];
		}
		else if (SecondFourBits[1] == 0 && SecondFourBits[2] == 1 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox22[3];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 0 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox22[4];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 0 && SecondFourBits[3] == 1)
		{
			sBox2Out = sBox22[5];
		}
		else if (SecondFourBits[1] == 1 && SecondFourBits[2] == 1 && SecondFourBits[3] == 0)
		{
			sBox2Out = sBox22[6];
		}
		else 
			sBox2Out = sBox22[7];
	}
	int box1OutArray[3];
	int box2OutArray[3];
	if (sBox1Out == 0)
	{
		box1OutArray[0] = 0;
		box1OutArray[1] = 0;
		box1OutArray[2] = 0;
	}
	else if (sBox1Out == 1)
	{
		box1OutArray[0] = 0;
		box1OutArray[1] = 0;
		box1OutArray[2] = 1;
	}
	else if (sBox1Out == 10)
	{
		box1OutArray[0] = 0;
		box1OutArray[1] = 1;
		box1OutArray[2] = 0;
	}
	else if (sBox1Out == 11)
	{
		box1OutArray[0] = 0;
		box1OutArray[1] = 1;
		box1OutArray[2] = 1;
	}
	else if (sBox1Out == 100)
	{
		box1OutArray[0] = 1;
		box1OutArray[1] = 0;
		box1OutArray[2] = 0;
	}
	else if (sBox1Out == 101)
	{
		box1OutArray[0] = 1;
		box1OutArray[1] = 0;
		box1OutArray[2] = 1;
	}
	else if (sBox1Out == 110)
	{
		box1OutArray[0] = 1;
		box1OutArray[1] = 1;
		box1OutArray[2] = 0;
	}
	else if (sBox1Out == 111)
	{
		box1OutArray[0] = 1;
		box1OutArray[1] = 1;
		box1OutArray[2] = 1;
	}
	
	if (sBox2Out == 0)
	{
		box2OutArray[0] = 0;
		box2OutArray[1] = 0;
		box2OutArray[2] = 0;
	}
	else if (sBox2Out == 1)
	{
		box2OutArray[0] = 0;
		box2OutArray[1] = 0;
		box2OutArray[2] = 1;
	}
	else if (sBox2Out == 10)
	{
		box2OutArray[0] = 0;
		box2OutArray[1] = 1;
		box2OutArray[2] = 0;
	}
	else if (sBox2Out == 11)
	{
		box2OutArray[0] = 0;
		box2OutArray[1] = 1;
		box2OutArray[2] = 1;
	}
	else if (sBox2Out == 100)
	{
		box2OutArray[0] = 1;
		box2OutArray[1] = 0;
		box2OutArray[2] = 0;
	}
	else if (sBox2Out == 101)
	{
		box2OutArray[0] = 1;
		box2OutArray[1] = 0;
		box2OutArray[2] = 1;
	}
	else if (sBox2Out == 110)
	{
		box2OutArray[0] = 1;
		box2OutArray[1] = 1;
		box2OutArray[2] = 0;
	}
	else if (sBox2Out == 111)
	{
		box2OutArray[0] = 0;
		box2OutArray[1] = 0;
		box2OutArray[2] = 0;
	}
	//combining both halfs and returning
	out[0] = box1OutArray[0];
	out[1] = box1OutArray[1];
	out[2] = box1OutArray[2];
	out[3] = box2OutArray[0];
	out[4] = box2OutArray[1];
	out[5] = box2OutArray[2];	
}

void enc(int n, int userkeyinput, char * stringinput){
	
	size_t len = strlen(stringinput);
	unsigned int *messagebits = malloc(sizeof(unsigned int)*(len-1));
	int key[9];
	int roundkey[8];

	//converting binary string to binary int array
	for (int i = 0; i < len-1; i++){
		messagebits[i] = stringinput[i] - '0';
	}

	//converts the input key from integer into an integer array
    int temp = 8;
    while (userkeyinput > 0)
    {
        int digit = userkeyinput % 10;
        userkeyinput /= 10;
        key[temp] = digit;
        temp--;
    }

    //padding
    int padsize = 12 - (len-1 % 12);
    
    //if the size of the input is a multiple of 12, padding will be 12 so we can get back the original
    //size of the input
    if ((len-1) % 12 == 0)   
    	padsize = 12;
	
    printf("Padsize: %i\n",padsize);

	unsigned int *messagebitspadded = malloc(sizeof(unsigned int)*(len+padsize-1));
	unsigned int *cipherbits = malloc(sizeof(unsigned int)*(len+padsize-1));

	//writing the input to a new array that will have the padding
	for (int i = 0; i < len-1; i++){
    	messagebitspadded[i] = messagebits[i];
    }

    //the first bit of padding will be a 1, and the rest 0s
    for (int i = 0; i < padsize; i++){
    	if (i == 0){
    		messagebitspadded[len+i-1] = 1;
    	}
   		else{
   			messagebitspadded[len+i-1] = 0;
    	}
    }

    free(messagebits);

	int k;
	unsigned int LeftStart[6];
	unsigned int RightStart[6];
	unsigned int LeftEnd[6];
	unsigned int RightEnd[6];
	int EncryptedR[6];

	//encrypting each block of the plaintext
	for (k = 0; k < ((len+padsize-1) / 12); k++){

		//first we split the message into a right side and left side
		for (int i = 0; i < 6; i++){
			LeftStart[i] = messagebitspadded[(12*k)+i];
			RightStart[i] = messagebitspadded[(12*k)+i+6];
		}
		
		//start of the rounds for one 12 bit block
		for (int j = 0; j < n; j++){
			//key determination
			if (((j + 1) % 9) == 1){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i];
			}
			else if (((j + 1) % 9) == 2){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i+1];
			}
			else if (((j + 1) % 9) == 3){
				for (int i = 0; i < 7; i++)
					roundkey[i] = key[i+2];
				roundkey[7] = key[0];
			}
			else if (((j + 1) % 9) == 4){
				for (int i = 0; i < 6; i++)
					roundkey[i] = key[i+3];
				for (int i = 0; i < 2; i++)
					roundkey[i+6] = key[i];
			}
			else if (((j + 1) % 9) == 5){
				for (int i = 0; i < 5; i++)
					roundkey[i] = key[i+4];
				for (int i = 0; i < 3; i++)
					roundkey[i+5] = key[i];
			}
			else if (((j + 1) % 9) == 6){
				for (int i = 0; i < 4; i++)
					roundkey[i] = key[i+5];
				for (int i = 0; i < 4; i++)
					roundkey[i+4] = key[i];
			}
			else if (((j + 1) % 9) == 7){
				for (int i = 0; i < 3; i++)
					roundkey[i] = key[i+6];
				for (int i = 0; i < 5; i++)
					roundkey[i+3] = key[i];
			}
			else if (((j + 1) % 9) == 8){
				for (int i = 0; i < 2; i++)
					roundkey[i] = key[i+7];
				for (int i = 0; i < 6; i++)
					roundkey[i+2] = key[i];
			}
			else {
				roundkey[0] = key[8];
				for (int i = 0; i < 7; i++)
					roundkey[i+1] = key[i];
			}

			f(RightStart, roundkey, EncryptedR);

			//XORing binary values of Left Side with output of function f
			for (int a = 0; a < 6; a++) 
				RightEnd[a] = LeftStart[a] ^ EncryptedR[a];

			for (int i = 0; i < 6; i++)
				LeftEnd[i] = RightStart[i];
			
			//assigning the ends as the new starts if n > 1 so it can be encrypted again
			for (int i = 0; i < 6; i++)
				LeftStart[i] = LeftEnd[i];
			for (int i = 0; i < 6; i++)
				RightStart[i] = RightEnd[i];
		}

		//assigning encrypted bits to one large array
		for (int i = 0; i < 6; i++){
			if ((((len+padsize-1) / 12) - k) == 1){
				cipherbits[(12*k)+i] = RightEnd[i];
				cipherbits[(12*k)+i+6] = LeftEnd[i]; 
			} 
			else {
			cipherbits[(12*k)+i] = LeftEnd[i];
			cipherbits[(12*k)+i+6] = RightEnd[i]; 
			}
		}
	}
	///////////////test
	printf("Cipherbits: ");
	for (int i = 0; i < len+padsize-1; i++)
		printf("%i", cipherbits[i]);

	free(cipherbits);
	free(messagebitspadded);

	putchar('\n');
}

void dec(int n, int userkeyinput, char *stringinput){
	size_t len = strlen(stringinput);
	unsigned int *cipherbits = malloc(sizeof(unsigned int)*(len-1));
	unsigned int *plainbits = malloc(sizeof(unsigned int)*(len-1));
	int key[9];
	int roundkey[8];

	//converting binary string to binary int array
	for (int i = 0; i < len-1; i++){
		cipherbits[i] = stringinput[i] - '0';
	}

	//converts the input key from integer into an integer array
    int temp = 8;
    while (userkeyinput > 0)
    {
        int digit = userkeyinput % 10;
        userkeyinput /= 10;
        key[temp] = digit;
        temp--;
    }

	unsigned int LeftStart[6];
	unsigned int RightStart[6];
	unsigned int LeftEnd[6];
	unsigned int RightEnd[6];
	int DecryptedR[6];
	
	//starting the block decryption
	for (int k = 0; k < (len-1 / 12); k++){
		
		//assigning the 6 bits for the left and right side
		for (int i = 0; i < 6; i++){
			LeftStart[i] = cipherbits[(12*k)+i];
			RightStart[i] = cipherbits[(12*k)+i+6];
		}

		//this loop will run n times, depending on what the user inputted
		for (int j = n; j > 0; j--){
			//key determination
			if ((j % 9) == 1){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i];
			}
			else if ((j % 9) == 2){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i+1];
			}
			else if ((j % 9) == 3){
				for (int i = 0; i < 7; i++)
					roundkey[i] = key[i+2];
				roundkey[7] = key[0];
			}
			else if ((j % 9) == 4){
				for (int i = 0; i < 6; i++)
					roundkey[i] = key[i+3];
				for (int i = 0; i < 2; i++)
					roundkey[i+6] = key[i];
			}
			else if ((j % 9) == 5){
				for (int i = 0; i < 5; i++)
					roundkey[i] = key[i+4];
				for (int i = 0; i < 3; i++)
					roundkey[i+5] = key[i];
			}
			else if ((j % 9) == 6){
				for (int i = 0; i < 4; i++)
					roundkey[i] = key[i+5];
				for (int i = 0; i < 4; i++)
					roundkey[i+4] = key[i];
			}
			else if ((j % 9) == 7){
				for (int i = 0; i < 3; i++)
					roundkey[i] = key[i+6];
				for (int i = 0; i < 5; i++)
					roundkey[i+3] = key[i];
			}
			else if ((j % 9) == 8){
				for (int i = 0; i < 2; i++)
					roundkey[i] = key[i+7];
				for (int i = 0; i < 6; i++)
					roundkey[i+2] = key[i];
			}
			else {
				roundkey[0] = key[8];
				for (int i = 0; i < 7; i++)
					roundkey[i+1] = key[i];
			}
			
			//inputting the right side of the block into the f function
			f(RightStart, roundkey, DecryptedR);

			//XORing binary values of Left Side with output of function f
			for (int a = 0; a < 6; a++) 
				RightEnd[a] = LeftStart[a] ^ DecryptedR[a];

			for (int i = 0; i < 6; i++)
				LeftEnd[i] = RightStart[i];
			
			//assigning the ends as the new starts if n > 1 so it can be encrypted again
			for (int i = 0; i < 6; i++)
				LeftStart[i] = LeftEnd[i];
			for (int i = 0; i < 6; i++)
				RightStart[i] = RightEnd[i];

		}
		
		//assigning encrypted bits to one large array
		for (int i = 0; i < 6; i++){
			if ((((len-1) / 12) - k) == 1){
				plainbits[(12*k)+i] = RightEnd[i];
				plainbits[(12*k)+i+6] = LeftEnd[i]; 
			} 
			else {
			plainbits[(12*k)+i] = LeftEnd[i];
			plainbits[(12*k)+i+6] = RightEnd[i]; 
			}
		}
		
	}

	//removing the padding by setting a pointer to the end of the array
	unsigned int *end, *beg;
	int count = 0;
	end = plainbits + (len-2);

	while (*end == 0){
		end--;
	}

	for (beg = plainbits; beg < end; ++beg)
		count++;

	///////////////test
	printf("Plainbits: ");
	for (int i = 0; i < count; i++)
		printf("%i", plainbits[i]);

	free(cipherbits);
	free(plainbits);
    putchar('\n');
}

void CBCenc(int n, int userkeyinput, char *stringinput){
	//using a static IV for now
	int IV[12] = {1,1,1,0,0,0,1,1,1,0,0,0};
	
	size_t len = strlen(stringinput);
	unsigned int *messagebits = malloc(sizeof(unsigned int)*(len-1));
	int key[9];
	int roundkey[8];

	//converting binary string to binary int array
	for (int i = 0; i < len-1; i++){
		messagebits[i] = stringinput[i] - '0';
	}
	
	//converts the input key from integer into an integer array
    int temp = 8;
    while (userkeyinput > 0)
    {
        int digit = userkeyinput % 10;
        userkeyinput /= 10;
        key[temp] = digit;
        temp--;
    }
	
    //padding
    int padsize = 12 - (len-1 % 12);
    
    if ((len-1) % 12 == 0)   
    	padsize = 12;
	
    printf("Padsize: %i\n",padsize);

	unsigned int *messagebitspadded = malloc(sizeof(unsigned int)*(len+padsize-1));
	unsigned int *cipherbits = malloc(sizeof(unsigned int)*(len+padsize-1));
	for (int i = 0; i < len-1; i++){
    	messagebitspadded[i] = messagebits[i];
    }
    for (int i = 0; i < padsize; i++){
    	if (i == 0){
    		messagebitspadded[len+i-1] = 1;
    	}
   		else{
   			messagebitspadded[len+i-1] = 0;
    	}
    }

    for (int i = 0; i < len - 1; i++)
    	printf("%i",messagebitspadded[i]);
    putchar('\n');
	
	free(messagebits);

	int k;
	int beforeXOR[12];
	unsigned int LeftStart[6];
	unsigned int RightStart[6];
	unsigned int LeftEnd[6];
	unsigned int RightEnd[6];
	int EncryptedR[6];
	int afterXOR[12];
	int cipherblock[12];
	
	//encrypting each block of the plaintext
	for (k = 0; k < ((len+padsize-1) / 12); k++){	

		//if the algorithm is on the first block, the plaintext will xor with the iv, 
		//otherwise it will xor with the previous ciphertext
		if (k == 0){
			for (int i = 0; i < 12; i++){
				beforeXOR[i] = messagebitspadded[i];
			}

			for (int i = 0; i < 12; i++){
				afterXOR[i] = beforeXOR[i] ^ IV[i];
			}
		}
		else {
			for (int i = 0; i < 12; i++){
				beforeXOR[i] = messagebitspadded[(12*k)+i];
			}
			for (int i = 0; i < 12; i++){
				afterXOR[i] = beforeXOR[i] ^ cipherblock[i];
			}
		}

		//assigning the 6 bits to go through the Light DES rounds
		for (int i = 0; i < 6; i++){
			LeftStart[i] = afterXOR[i];
			RightStart[i] = afterXOR[i+6];
		}

		//start of the rounds for one 12 bit block
		for (int j = 0; j < n; j++){
			//key determination
			if (((j + 1) % 9) == 1){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i];
			}
			else if (((j + 1) % 9) == 2){
				for (int i = 0; i < 8; i++)
					roundkey[i] = key[i+1];
			}
			else if (((j + 1) % 9) == 3){
				for (int i = 0; i < 7; i++)
					roundkey[i] = key[i+2];
				roundkey[7] = key[0];
			}
			else if (((j + 1) % 9) == 4){
				for (int i = 0; i < 6; i++)
					roundkey[i] = key[i+3];
				for (int i = 0; i < 2; i++)
					roundkey[i+6] = key[i];
			}
			else if (((j + 1) % 9) == 5){
				for (int i = 0; i < 5; i++)
					roundkey[i] = key[i+4];
				for (int i = 0; i < 3; i++)
					roundkey[i+5] = key[i];
			}
			else if (((j + 1) % 9) == 6){
				for (int i = 0; i < 4; i++)
					roundkey[i] = key[i+5];
				for (int i = 0; i < 4; i++)
					roundkey[i+4] = key[i];
			}
			else if (((j + 1) % 9) == 7){
				for (int i = 0; i < 3; i++)
					roundkey[i] = key[i+6];
				for (int i = 0; i < 5; i++)
					roundkey[i+3] = key[i];
			}
			else if (((j + 1) % 9) == 8){
				for (int i = 0; i < 2; i++)
					roundkey[i] = key[i+7];
				for (int i = 0; i < 6; i++)
					roundkey[i+2] = key[i];
			}
			else {
				roundkey[0] = key[8];
				for (int i = 0; i < 7; i++)
					roundkey[i+1] = key[i];
			}

			f(RightStart, roundkey, EncryptedR);

			for (int i = 0; i < 6; i++){
				RightEnd[i] = LeftStart[i] ^ EncryptedR[i];
			}

			for (int i = 0; i < 6; i++){
				LeftEnd[i] = RightStart[i];
			}

			//assigning the ends as the new starts if n > 1 so it can be encrypted again
			for (int i = 0; i < 6; i++)
				LeftStart[i] = LeftEnd[i];
			for (int i = 0; i < 6; i++)
				RightStart[i] = RightEnd[i];
		}	
		
		//assigning encrypted bits to one large array
		for (int i = 0; i < 6; i++){
			if ((((len+padsize-1) / 12) - k) == 1){
				cipherbits[(12*k)+i] = RightEnd[i];
				cipherbits[(12*k)+i+6] = LeftEnd[i]; 
			} 
			else {
			cipherbits[(12*k)+i] = LeftEnd[i];
			cipherbits[(12*k)+i+6] = RightEnd[i]; 
			}
		}

		//so the next plaintext block has something to xor with
		for (int i = 0; i < 12; i++){
			if (i < 6)
				cipherblock[i] = LeftEnd[i];
			else
				cipherblock[i] = RightEnd[i-6];
		}
	}

	printf("Cipherbits: ");
	for (int i = 0; i < len-1; i++) {
		printf("%i", cipherbits[i]);
	}
	putchar('\n');

	free(messagebitspadded);
	free(cipherbits);
}

int main(int argc, char *argv[]){
	int userkeyinput, n;
	char *stringinput = calloc(1000, sizeof(char));

	if (argv[1] == NULL) {
        printf("Missing --ECB/--CBC, --enc/--dec, n rounds and key.\n");
        exit(1);
    }

	if (argv[2] == NULL) {
        printf("Missing --enc/--dec, n rounds and key.\n");
        exit(1);
    }

	if (argv[3] == NULL) {
        printf("Missing n rounds and key.\n");
        exit(1);
    }

    if (argv[4] == NULL || strlen(argv[4]) != 9){
    	printf("Please input a key of a 9 bit length.\n");
    	exit(1);
    }

	n = atoi(argv[3]);
	userkeyinput = atoi(argv[4]);

	if (strcmp(argv[1], "--ECB") == 0){
		if (strcmp(argv[2], "--enc") == 0){
			printf("Enter binary to be encrypted: \n");
			fgets(stringinput, 1000, stdin);
			enc(n, userkeyinput, stringinput);
		}	
		else if (strcmp(argv[2], "--dec") == 0){
			printf("Enter binary with length of a multiple of 12 that you would like to decrypt: \n");
			fgets(stringinput,1000, stdin);
			dec(n, userkeyinput, stringinput);
		}
	} 
	else if (strcmp(argv[1], "--CBC") == 0)
	{
		if (strcmp(argv[2], "--enc") == 0){
			printf("Enter binary to be encrypted: \n");
			fgets(stringinput, 1000, stdin);
			CBCenc(n, userkeyinput, stringinput);
		}	
		else if (strcmp(argv[2], "--dec") == 0){
			/*
			printf("Enter binary with length of a multiple of 12 that you would like to decrypt: \n");
			fgets(stringinput,1000, stdin);
			dec(n, userkeyinput, stringinput);
			*/
			printf("CBC dec not implemented.\n");
		}
	} 
	else if (strcmp(argv[1], "--CTR") == 0){
		printf("CTR not implemeneted.\n");
	} 	
	else
		printf("Please input --ECB or --CBC");

	free(stringinput);

	return 0;
}
