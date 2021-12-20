#include "teZZt.h"
#include "mon_code.h"
#include <string.h>

BEGIN_TEST_GROUP(pgcd)

TEST(pgcd1) {

   CHECK( 12 == pgcd(36, 24) );
   CHECK(  3 == pgcd(96, 81) );
   CHECK(  1 == pgcd(17,  1) );

}

TEST(pgcd2) {

   CHECK( 12 == pgcd(24, 36) );
   CHECK(  3 == pgcd(81, 96) );
   CHECK(  1 == pgcd( 1, 17) );

}

/* // on teste avec des entrees negatives ?
TEST(pgcd3) {

   

} */



TEST(maj1) {
	char s[255] = "";

    majuscules(s);
 
    CHECK(  0 == strcmp( s, "") );
}

TEST(maj2) {
	char s[255] = "ABCD";

    majuscules(s);
 
    CHECK(  0 == strcmp( s, "ABCD") );
}

TEST(maj3) {
	char s[255] = "abcd";

    majuscules(s);
 
    CHECK(  0 == strcmp( s, "ABCD") );
}

TEST(maj4) {
	char s[255] = "aAbB2eDdD!";

    majuscules(s);
 
    CHECK(  0 == strcmp( s, "AABB2EDDD!") );
}



END_TEST_GROUP(pgcd)


int main(void) {
	RUN_TEST_GROUP(pgcd); 
 	return 0;
}
