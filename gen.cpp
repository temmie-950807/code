#include "testlib.h"

using namespace std;

const int mx = 1e9;

int main(int argc, char* argv[])
{
	registerGen(argc, argv, 1);
	
	int q = 1000,id = rnd.next(990,1000);
	for(int i=0;i<q;i++)
	{
		if( i == q - 1 )
		{
			cout << "close\n";
			break;
		}
		
		int r = rnd.next(1,3);
		if( r == 1 )
		{
			long long hash = (long long)rnd.next(1,mx) * rnd.next(1,mx);
			cout << "pancake " << id << " " << hash << "\n";
		}
		else if( r == 2 )
		{
			string s = "";
			for(int i=0;i<10;i++)
			{
				int u = rnd.next(1,2) , add = rnd.next(0,25);
				if( u == 1 ) s += (char)('a' + add);
				else s += (char)('A' + add);
			}
			
			cout << "customer " << s << "\n";
		}
		else
		{
            // [sold out / sell] ratio is [0.5 / 0.5]
            int output_id;
            if (rnd.next(0, 1)){
			    output_id = rnd.next(990,1000);
            }else{
                output_id = id;
            }
			cout << "sell " << output_id << "\n";
		}
	}
	
	return 0;
}
