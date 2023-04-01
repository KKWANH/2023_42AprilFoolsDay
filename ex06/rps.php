#!/usr/bin/env php
<?php

$bold	= "\033[1m";
$reset	= "\033[0m";

$green	= "\033[32m";
$red	= "\033[31m";
$yellow	= "\033[33m";
$cyan	= "\033[36m";

echo "Choose rock, paper, or scissors: ";
$input = trim(fgets(STDIN));

if ($input === "") {
    echo "{$yellow}{$bold}Error! Empty string entered.{$reset}{$yellow} Please enter a valid choice.{$reset}\n";
    exit;
}

$choices = ['rock', 'paper', 'scissors'];
$computer_choice = $choices[array_rand($choices)];

if ($input === $computer_choice) {
    echo "{$bold}{$cyan}It's a draw!{$reset}{$cyan} You both chose {$input}.\n";
} else {
    $winning_combinations = [
        'rock' => 'scissors',
        'paper' => 'rock',
        'scissors' => 'paper'
    ];

    if (isset($winning_combinations[$input]) && $winning_combinations[$input] === $computer_choice) {
        echo "{$green}{$bold}Congratulations!{$reset}{$green} You won! The computer chose {$computer_choice}.{$reset}\n";
    } else {
        echo "{$red}{$bold}Sorry, you lost.{$reset}{$red} The computer chose {$computer_choice}.{$reset}\n";
    }
}

?>