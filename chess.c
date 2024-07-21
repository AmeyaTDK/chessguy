#include<stdio.h>

int main(){

	enum tpiece{
		K;
		Q;
		R;
		B;
		N;
		P;
	};

	struct square{
		bool present;
		struct piece*;
	};
	
	struct piece{
		bool colour;
		struct position*;
		enum tpiece;
	};
	
	struct move{
		struct piece*;
		struct square*;
	};
	
	struct position{
		int x;
		int y;
	}

}
