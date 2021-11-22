#include <ArduinoFake.h>
#include <unity.h>


using namespace fakeit;

void setUp(void)
{
    ArduinoFakeReset();
}


void test_loop(void)
{
}

void test_setup(void)
{
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), analogReference)).AlwaysReturn();
    //When(Method(ArduinoFake(Serial), begin)).AlwaysReturn();
    When(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long))).AlwaysReturn();
    //When(Method(ArduinoFake(raPressure), clear)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();
    //When(Method(ArduinoFake(), beep_motor)).AlwaysReturn();
    setup();
    Verify(Method(ArduinoFake(), pinMode).Using(5, INPUT));
    Verify(Method(ArduinoFake(), digitalWrite).Using(5, HIGH));
    Verify(Method(ArduinoFake(), analogReference).Using(EXTERNAL));
    Verify(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long)).Using(115200)).Once();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_loop);
    RUN_TEST(test_setup);

    UNITY_END();

    return 0;
}
