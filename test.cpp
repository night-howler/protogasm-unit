#include <ArduinoFake.h>

using namespace fakeit;

int main(void)
{
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    loop();

    Verify(Method(ArduinoFake(), delay).Using(100)).Exactly(2_Times);
}
