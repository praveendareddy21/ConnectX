
Praveen Dareddy


ConnectX Bugs:

- Method inBounds is giving incorrect result when height is inside the bounds and the width is out of bounds. This bug is 
also causing another method placePiece to coredump sometimes when the placePiece is called on invalid width as inbounds call in placepiece always return true.


- Constructor is not checking if to_win parameter is greater than height and width. This will make the Connectx to not have any winner.
