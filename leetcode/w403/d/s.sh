for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./ < int) <(./brute < int) || break
done
