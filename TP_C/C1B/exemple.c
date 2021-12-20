#include "teZZt.h"
#include "mon_code.h"

BEGIN_TEST_GROUP(pgcd)

// the second parameter is used for comment, not currently used 
TEST(A, "test pas bon mais qui continue") {
   int b =3;
 
   CHECK(0==b);
}

TEST(B, "test bon") {
	int b = 3;

    REQUIRE(3==b);
}

TEST(C, "test pas bon mais et qui arrete\n") {
	int b = 3;
	
    REQUIRE(0==b);
}

TEST(D) {
	int b = 3;
	
    REQUIRE(0==b);
}

TEST(E) {
	BUFFER(buffer) -> buffer.file buffer.string buffer.size
	//test de sortie
	FILE * file = fmemopen(buffer, 1024, "w");
   // REQUIRE ( NULL != file); // creation du fichier impossible ?

   vecteurToFile(file, v1, 3);
   fclose(file);

   // verification de ce qui est envoye sur le flux
   // chaque composante est affichee avec trois chiffre apres la virgule
   // %.3f
   CHECK( 0==strcmp(buffer, "[ 1.000 2.000 3.000 ]") );


}

END_TEST_GROUP(pgcd)


int main(void) {
	RUN_TEST_GROUP(pgcd); 
 	return 0;
}
