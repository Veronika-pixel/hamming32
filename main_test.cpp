#include <UnitTest++/UnitTest++.h>
#include <../hamming32/hamming32.cpp>

struct Hamming32_fixture {
	Hamming32 * object;
	Hamming32_fixture() {
		object = new Hamming32();
	}
	~Hamming32_fixture() {
		delete object;
	}
};

SUITE(EncodeTest)
{
	TEST_FIXTURE(Hamming32_fixture, CorrectData){
		object->encode("TesT*2!");
		CHECK(true);
	}
	TEST_FIXTURE(Hamming32_fixture, EmptyString){
		CHECK_THROW(object->encode(""), error_hamming);
	}
	TEST_FIXTURE(Hamming32_fixture, InvalidCharacter){
		CHECK_THROW(object->encode("TeФз12"), error_hamming);
	}
}


SUITE(DecodeTest) {
	vector<int> vec1 {1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0};
	TEST_FIXTURE(Hamming32_fixture, CorrectData){
		object->decode(vec1);
		CHECK(true);
	}
	vector<int> vec2;
	TEST_FIXTURE(Hamming32_fixture, EmptyString){
		CHECK_THROW(object->decode(vec2), error_hamming);
	}
	vector<int> vec3{1,0,0,0,1};
	TEST_FIXTURE(Hamming32_fixture, InvalidCharacter){
		CHECK_THROW(object->decode(vec3), error_hamming);
	}
	vector<int> vec4{1,0,0,1,5,2,3,6,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	TEST_FIXTURE(Hamming32_fixture, IncorrectLength){
		CHECK_THROW(object->decode(vec4), error_hamming);
	}
	vector<int> vec5{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	TEST_FIXTURE(Hamming32_fixture, ZeroVector){
		CHECK_THROW(object->decode(vec5), error_hamming);
	}
	
}

int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}
