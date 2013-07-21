/*
 * Copyright (c) 2013 by Kyle Isom <kyle@tyrfingr.is>.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#include <avr/io.h>

#include "serial.h"

static void
ok(void)
{
	unsigned char	ok[] = "ok\r\n";

	PORTB |= (1 << 0);
	serial_transmit(ok, 4);
	PORTB &= (0 << 0) | (1 << 5);
}

static void
echo(void)
{
	unsigned char	in;

	while (1) {
		in = serial_block_receive_byte();
		serial_block_transmit_byte(in);
	}
}

int
main(void)
{
	serial_init(9600, 0);

	PORTB |= (1 << 5);
	ok();
	echo();
	return 0;
}
