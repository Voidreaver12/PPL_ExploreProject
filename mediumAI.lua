-- Get game board as a string
board = getBoard()

-- Seed random generator
s = isSeeded()
if (not s) then
	math.randomseed( os.time() )
	seed()
end

-- Used for [] index access of string
getmetatable('').__index = function(str, i) return string.sub(str,i,i) end

-- Try to block player from winning,
-- otherwise move randomly
function getMove ()
	if     (board[1] == 'X' and board[2] == 'X' and board[3] == '3') then return 3
	elseif (board[1] == 'X' and board[3] == 'X' and board[2] == '2') then return 2
	elseif (board[2] == 'X' and board[3] == 'X' and board[1] == '1') then return 1

	elseif (board[4] == 'X' and board[5] == 'X' and board[6] == '6') then return 6
	elseif (board[4] == 'X' and board[6] == 'X' and board[5] == '5') then return 5
	elseif (board[5] == 'X' and board[6] == 'X' and board[4] == '4') then return 4

	elseif (board[7] == 'X' and board[8] == 'X' and board[9] == '9') then return 9
	elseif (board[7] == 'X' and board[9] == 'X' and board[8] == '8') then return 8
	elseif (board[8] == 'X' and board[9] == 'X' and board[7] == '7') then return 7

	elseif (board[1] == 'X' and board[4] == 'X' and board[7] == '7') then return 7
	elseif (board[1] == 'X' and board[7] == 'X' and board[4] == '4') then return 4
	elseif (board[4] == 'X' and board[7] == 'X' and board[1] == '1') then return 1

	elseif (board[2] == 'X' and board[5] == 'X' and board[8] == '8') then return 8
	elseif (board[2] == 'X' and board[8] == 'X' and board[5] == '5') then return 5
	elseif (board[5] == 'X' and board[8] == 'X' and board[2] == '2') then return 2

	elseif (board[3] == 'X' and board[6] == 'X' and board[9] == '9') then return 9
	elseif (board[3] == 'X' and board[9] == 'X' and board[6] == '6') then return 6
	elseif (board[6] == 'X' and board[9] == 'X' and board[3] == '3') then return 3

	elseif (board[3] == 'X' and board[5] == 'X' and board[7] == '7') then return 7
	elseif (board[3] == 'X' and board[7] == 'X' and board[5] == '5') then return 5
	elseif (board[5] == 'X' and board[7] == 'X' and board[3] == '3') then return 3

	elseif (board[1] == 'X' and board[5] == 'X' and board[9] == '9') then return 9
	elseif (board[1] == 'X' and board[9] == 'X' and board[5] == '5') then return 5
	elseif (board[5] == 'X' and board[9] == 'X' and board[1] == '1') then return 1
	end

	return math.random(9)

end


position = getMove()
cpuMove(position)
