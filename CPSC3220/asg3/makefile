all: btrfs_1.c btrfs_2.c btrfs_driver1.c btrfs.h
	clang btrfs_1.c btrfs_2.c btrfs_driver1.c -o driver

run: all
	./driver

clean:
	rm driver
