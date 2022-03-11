# Usage Examples

# Table of Contents

1. [Introduction](#Introduction)
2. [Creating/updating a timer](#Creating/updating-a-Timer)
3. [Viewing a Timer](#Viewing-a-Timer)
4. [Viewing all Timers](#Viewing-all-Timers)
5. [Deleting a Timer](#Deleting-a-Timer)

## Introduction

Once you have downloaded/built the LWCountdown executable, add LWCountdown to your machine's path.

You will now be able to use LWCountdown from your computer's terminal.

If you see the help message, you are now ready to use LWCountdown.

```
$ LWCountdown -h

LWCountdown: C++ CLI countdown timer
Usage: LWCountdown [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -c TEXT                     Create/update a timer
  -v TEXT                     View a timer
  -a                          View all timers
  -d TEXT                     Delete a timer
```

## Creating/updating a Timer

```
$ LWCountdown -c "Independence Day"

Name of timer: Independence Day
    End date: 2022-7-4
Timer "Independence Day" has been set
    Time remaining: 211 days
	
$ LWCountdown -c "Christmas Day"

Name of timer: Christmas Day
    End date: 2021-12-25
Timer "Christmas Day" has been set
    Time remaining: 20 days
```

## Viewing a Timer

```
$ LWCountdown -v "Christmas Day"

Timer selected: Christmas Day
    Time remaining: 20 days
```

## Viewing all Timers

```
$ LWCountdown -a

Showing all timers

Christmas Day
    Time remaining: 20 days
Independence Day
    Time remaining: 211 days
```

## Deleting a Timer

```
$ LWCountdown -d "Independence Day"

Timer "Independence Day" has been deleted
```
