/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};


TEST(ConnectXTest, ConstructorWithGivenDimen)
{
  ConnectX c(5,5,2);
  c.placePiece(0);
	ASSERT_EQ(c.at(0,4), 2);
}

TEST(ConnectXTest, ConstructorWithInvalidHeight)
{
  ConnectX c(5,-1,2);
	ASSERT_EQ(2,c.whoseTurn());
}
TEST(ConnectXTest, ConstructorWithInvalidWidth)
{
  ConnectX c(-1,5,2);
  ASSERT_EQ(2,c.whoseTurn());
}
TEST(ConnectXTest, ConstructorWithInvalidToWin)
{
  ConnectX c(5,5,-2);
  ASSERT_EQ(2,c.whoseTurn());
}

TEST(ConnectXTest, whoseTurnStartswithBlack)
{
  ConnectX c;
  ASSERT_EQ(c.whoseTurn(), 2);
}

TEST(ConnectXTest, toggleTurnToWhite)
{
  ConnectX c;
  ASSERT_EQ(c.whoseTurn(), 2);
  c.placePiece(0);
  ASSERT_EQ(c.whoseTurn(), 1);

}

TEST(ConnectXTest, toggleTurnToBlackAgain)
{
  ConnectX c;

  c.placePiece(0);
  ASSERT_EQ(c.whoseTurn(), 1);
	c.placePiece(0);
	ASSERT_EQ(c.whoseTurn(), 2);

}

TEST(ConnectXTest, inBoundsTrueforValidAt0and0)
{
  ConnectX c;

  ASSERT_EQ(0, c.at(0,0));


}

TEST(ConnectXTest, inBoundsTrueforValidValues)
{
  ConnectX c;

  ASSERT_EQ(0, c.at(2,2));
}
TEST(ConnectXTest, inBoundsFalseforInvalidWidthHeight)
{
  ConnectX c;
  ASSERT_EQ(-1, c.at(10,10));
}


TEST(ConnectXTest, inBoundsFalseforInvalidHeight)
{
  ConnectX c;
  ASSERT_EQ(-1, c.at(4,-1));

}

TEST(ConnectXTest, inBoundsFalseforInvalidWidth)
{
  ConnectX c;
  ASSERT_EQ(-1, c.at(-1,4));
}


TEST(ConnectXTest, placePiecefilledColumn)
{
  ConnectX c(3,3,2);
	c.placePiece(1);
	c.placePiece(1);
	c.placePiece(1);
	c.placePiece(1);

	ASSERT_EQ(2, c.whoseTurn());

}

TEST(ConnectXTest, placePieceColumnCheck)
{
  ConnectX c(3,3,2);
	c.placePiece(0);
	c.placePiece(1);
	c.placePiece(2);


	ASSERT_EQ(2, c.at(0,2));
	ASSERT_EQ(1, c.at(1,2));
	ASSERT_EQ(2, c.at(2,2));


}


TEST(ConnectXTest, ShowBoardTest)
{
  ConnectX c;
	c.placePiece(1);
	c.placePiece(1);
	c.placePiece(0);
	c.placePiece(2);

	c.showBoard();
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, placePieceatInvalidWidth)
{
  ConnectX c;
	c.placePiece(8);

	ASSERT_EQ(1, c.whoseTurn());
}
