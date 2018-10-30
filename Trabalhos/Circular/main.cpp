#include <iostream> 

#include "gtest/gtest.h"
#include "node.h"
#include "list.h"
#include "tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
