#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
#  mod11.py
#  
#  Copyright 2021 mike <mike@pop-os>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

import math

def main(args):
	modulus = 13
	for i in range(0,1200):
		j = ((10*i + 7) % 3)
		k = ((10*i + 7) % 11)
		l = ((10*i + 7) % 13)
		if( (j==0)and(k==0)and(l==0) ):
			print(i, 10*i + 7)
	return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
