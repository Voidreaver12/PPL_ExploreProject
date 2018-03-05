
-- Seed
s = isSeeded()
if (not s) then
	math.randomseed( os.time() )
	seed()
end

-- Pick random number 1-9 and try to play on that position
position = math.random(9)
cpuMove(position)
