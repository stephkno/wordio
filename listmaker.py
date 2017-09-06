dict = open('words', 'r')
dictwords = dict.read().splitlines()

i = 1

for word in dictwords:
	if len(word) > 1:
		print word
