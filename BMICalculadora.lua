io.write "Enter your weight in kg: "
weight = io.read()
io.write "Enter your height in meters: "
height = io.read()

bmi = weight / (height * height)

print("Your BMI is: "..bmi)

if bmi <= 18.5 then
    output="You're underweight"
elseif bmi <= 25 then
    output="You're healthy"
elseif bmi <= 30 then
    output="You're overweight"
else
    output="Whales can't use computers!"
end

print(output)
