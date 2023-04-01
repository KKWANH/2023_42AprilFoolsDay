#!/usr/bin/perl
use strict;
use warnings;

print "Enter a string: ";
my $input = <STDIN>;
chomp $input;

my $reversed = reverse $input;

my $reset 	= "\033[0m";
my $strong 	= "\033[1m\033[4m";
my $yellow 	= "\033[33m";
my $red 	= "\033[31m";
my $green 	= "\033[32m";

if ($input eq "") {
    print $strong, $yellow, "[Error]", $reset, $yellow, "   Empty string entered. Please enter a valid string.\n";
} elsif (lc($input) eq lc($reversed)) {
    print $strong, $green, "[Success]", $reset, $green, " The string is a palindrome!\n";
} else {
    print $strong, $red, "[Failure]", $reset, $red, " The string is not a palindrome.\n";
}
print $reset