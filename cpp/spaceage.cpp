/*Given an age in seconds, calculate how old someone would be on:

Mercury: orbital period 0.2408467 Earth years
Venus: orbital period 0.61519726 Earth years
Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds
Mars: orbital period 1.8808158 Earth years
Jupiter: orbital period 11.862615 Earth years
Saturn: orbital period 29.447498 Earth years
Uranus: orbital period 84.016846 Earth years
Neptune: orbital period 164.79132 Earth years
So if you were told someone were 1,000,000,000 seconds old, you should be able to say that they're 31.69 Earth-years old.

*/

#include <iostream>

void spaceAge(long ageInSeconds);

int main()
{
    int jason = 12064320*60;
    spaceAge(jason);
    
    return 0;
}

void spaceAge(long ageInSeconds)
{
    double earth_age = ageInSeconds/(86400*365.25);
    double mercury_age = earth_age/0.2408467;
    double venus_age = earth_age/0.61519726;
    double mars_age = earth_age/1.8808158;
    double jupiter_age = earth_age/11.862615;
    double saturn_age = earth_age/29.447498;
    double uranus_age = earth_age/84.016846;
    double neptune_age = earth_age/164.79132;

    std::cout << "Age in seconds: " << ageInSeconds << "\n"
              << "Age in Mercury years: " << mercury_age << "\n"
              << "Age in Venus years: " << venus_age << "\n"
              << "Age in Earth years: " << earth_age << "\n"
              << "Age in Mars years: " << mars_age << "\n"
              << "Age in Jupiter years: " << jupiter_age << "\n"
              << "Age in Saturn years: " << saturn_age << "\n"
              << "Age in Uranus years: " << uranus_age << "\n"
              << "Age in Neptune years: " << neptune_age << "\n";
}