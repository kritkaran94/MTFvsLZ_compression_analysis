/*


 Author : Krit Karan Singh
 Roll : IS201311018
 Indian Instiute Of Information Technology, Sri City

*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


#define L int
#define LL long long int
#define C char
#define rep(i,a,n) for(int i = a ; i<=n ; i++)


// Inverse Move-To-Front Transform

/*
   
   Given a symbol table of a zero-indexed array of all possible input symbols this algorithm
   eversibly transforms a sequence of input symbols into an array of output numbers (indices).

   
   Inverse Move-To-Front Transform
   
   Pseudocode:

   for every index search an alphabet in Symbol Table
   move that alphabet then to the beginining in Symbol Table.

   
    
*/

class MTF
{

public:
    
    // Transform

    string encode( string str )
    {
	
	  SymbolTable();
	  
	  vector<int> output; // Output Vector contains all the Indexes

	  for( string::iterator it = str.begin(); it != str.end(); it++ )
	  {
	    rep(i,0,25)
	    {
		  if( *it == symbolTable[i] )
		  {
		    
		    output.push_back( i ); 
		    moveFront( i );
		    break;

		   }
	    }
	  }

	 string result;
	 
	 for( vector<int>::iterator it = output.begin(); it != output.end(); it++ )
	 {
	    ostringstream ss;
	    ss << *it;
	    result += ss.str() + " ";
	 }
	
	 return result;
    }

    string decode(string str)
    {
      
      SymbolTable();

      istringstream iss( str ); 
      vector<L> output;


      copy( istream_iterator<L>( iss ), istream_iterator<L>(), back_inserter<vector<L> >( output ) );
      string result;


      for( vector<L>::iterator it = output.begin(); it != output.end(); it++ )
      {
        
        result.append( 1, symbolTable[*it] );
        moveFront( *it );
      }
        
       return result;
    }
   
 
private:

    
    void SymbolTable()
    {
        rep(x,0,25)
	    symbolTable[x] = x + 'a';
    }
    
    void moveFront( L i )
    {

	  C t = symbolTable[i];
	  for( L z = i - 1; z >= 0; z-- )
	    symbolTable[z + 1] = symbolTable[z];
 
        symbolTable[0] = t;
    }
 

    char symbolTable[26];
};
 
L main()
{
    MTF mtf;
    string a, str[] = { "parvez", "bananaaa", "yasmeen" };
    rep(x,0,2)
    {
        a = str[x];
        cout << a << " -> encoded = ";
        a = mtf.encode( a );
        cout << a << "; decoded = " << mtf.decode( a ) << endl;
    }
    return 0;
}