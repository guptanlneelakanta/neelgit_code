disct1={"key1": "val1", "key2": "val2", "key3": "val3", "key4": "val4"}

print(disct1)

for key in disct1:
	print(key)

print("values")

for value in disct1.values():
	print(value)
	
for key, value in disct1.items():
	print(key + ":" + value)
	
if "key1" in disct1:
	print("\n key1 is present in disct1")
	
squares = {x:x**2  for x  in range (1, 6)}

print("\n squares disct:", squares)
	
