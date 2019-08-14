#include <iostream>
#include <chrono>

float random(float low, float high) {
	static bool seeded;

	if (!seeded) {
		//seed srand() with system milliseconds for better variability when calling rand()
		unsigned __int64 seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		srand(seed);
		seeded = true;
	}
	return low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
}

int main(){
  //print a random number between -10 and +10
  std::cout << random(-10, 10) << endl;
}
