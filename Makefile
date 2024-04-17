CFLAGS:=-O0 -g

vanilla: main.c lib.c
	clang -O0 -g main.c lib.c -o vanilla

vanilla.bc: main.c lib.c
	~/node_modules/llvm-14.0.0.obj/bin/clang-14 $(CFLAGS) -emit-llvm -c main.c -o main.bc
	~/node_modules/llvm-14.0.0.obj/bin/clang-14 $(CFLAGS) -emit-llvm -c lib.c -o lib.bc
	~/node_modules/llvm-14.0.0.obj/bin/llvm-link main.bc lib.bc -o vanilla.bc
	~/node_modules/llvm-14.0.0.obj/bin/llvm-dis vanilla.bc -o vanilla.ll

vanilla.json: vanilla.bc
	~/objenc/pcggen/build/objenc ./vanilla.bc vanilla.json

safe: main.c lib.c
	~/storage/lava/llvm-lava/build/bin/clang-12 $(CFLAGS) main.c lib.c -o safe -lmemorizer

epcg: safe vanilla.json
	~/objenc/analysis/parse_perm.py --bin safe --pcg vanilla.json --embed-inplace
