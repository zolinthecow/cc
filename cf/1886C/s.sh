for ((i = 1; ; ++i)); do
	echo $i
	# ./gen $i > int
	# diff -w <(./ < int) <(./brute < int) || break
	./gen $i > 1886C.in
	./1886C
done
