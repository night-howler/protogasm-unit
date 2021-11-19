#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

void setUp(void)
{
    ArduinoFakeReset();
}


void test_loop(void)
{
    When(Method(ArduinoFake(), delay)).AlwaysReturn();
    loop();
    Verify(Method(ArduinoFake(), delay).Using(100)).Exactly(2_Times);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_loop);

    UNITY_END();

    return 0;
}
