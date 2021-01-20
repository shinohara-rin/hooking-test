all: clean victim libshit test

victim: 
	cc victim.c -o victim

libshit:
	cc libshit.c mach_override/*.c mach_override/libudis86/*.c -shared -fPIC -o libshit.dylib -Wno-everything

test:
	#======ORIGINAL======
	./victim
	#=======HOOKED=======
	DYLD_INSERT_LIBRARIES=libshit.dylib ./victim

clean:
	rm victim libshit.dylib