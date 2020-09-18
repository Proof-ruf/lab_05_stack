// Copyright 2018 Your Name <your_email>


#include <gtest/gtest.h>
#include <header.hpp>
#include <type_traits>


class Length{
 public:
  int sum;
  Length() {}
  Length(std::string S1, std::string S2){
    sum = S1.length() + S2.length();
  }
  explicit Length(std::string S1){
    sum = S1.length();
  }
};

TEST(one, EmptyTest) {
Stack<int> Stack_1(30);
int var_1 = 6;
int var_2 = 8;
int var_3 = 10;
Stack_1.push(var_1);
Stack_1.push(var_2);
Stack_1.pop();
Stack_1.push(var_3);
EXPECT_EQ(static_cast<int>(Stack_1.head()), 10);
}


TEST(two, EmptyTest) {
Length obj("Malo");
stack<Length> Stack_2(30);
Stack_2.push_emplace("Halo", "Dasha");
Stack_2.push(std::move(obj));
EXPECT_EQ(Stack_2.pop().sum, 4);
}


TEST(three, EmptyTest) {
EXPECT_EQ(std::is_move_constructible<Stack<int>>::value, true);
EXPECT_EQ(std::is_move_assignable<Stack<int>>::value, true);
EXPECT_EQ(std::is_move_constructible<stack<int>>::value, true);
EXPECT_EQ(std::is_move_assignable<stack<int>>::value, true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

