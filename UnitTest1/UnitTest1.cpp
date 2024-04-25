#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.3(1)/lab12.3(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(SwapNodesTest) {

            int values[] = { 1, 2, 3, 4, 5 };
            int expected_values[] = { 2, 1, 4, 3, 5 };
            Node* expectedList = createList(expected_values, 5);
            Node* actualList = createList(values, 5);

            swapAdjacentNodes(actualList);

            Node* currentActual = actualList;
            Node* currentExpected = expectedList;
            bool areEqual = true;
            while (currentActual != nullptr && currentExpected != nullptr) {
                if (currentActual->data != currentExpected->data) {
                    areEqual = false;
                    break;
                }
                currentActual = currentActual->next;
                currentExpected = currentExpected->next;
            }
            if (currentActual != nullptr || currentExpected != nullptr) {
                areEqual = false;
            }
            Assert::IsTrue(areEqual, L"Lists do not match after swapping adjacent nodes.");

            deleteList(actualList);
            deleteList(expectedList);
        }
	};
}