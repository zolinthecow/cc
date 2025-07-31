for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./2117E < int) <(./brute < int) || break
done
