// Copyright (c) 2013 Heapsource.com and Contributors - http://www.heapsource.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


#include <stdio.h>
#include <stdlib.h>
#include "http_parser.h"

http_parser * duv_alloc_http_parser() {
  return calloc(1, sizeof(http_parser));
}

void duv_free_http_parser(http_parser * parser) {
  free(parser);
}

const char * duv_http_errno_name(http_parser *parser) {
  enum http_errno err = HTTP_PARSER_ERRNO(parser);
  return http_errno_name(err);
}

const char * duv_http_errno_description(http_parser *parser) {
  enum http_errno err = HTTP_PARSER_ERRNO(parser);
  return http_errno_description(err);
}

void * duv_get_http_parser_data(http_parser * parser) {
  return parser->data;
}

void duv_set_http_parser_data(http_parser * parser, void* data) {
  parser->data = data;
}

unsigned char duv_http_parser_get_errno(http_parser * parser) {
  return parser->http_errno;
}

const char * duv_http_method_str(http_parser * parser) {
    return http_method_str(parser->method);
}

unsigned short duv_http_major(http_parser * parser) {
    return parser->http_major;
}
unsigned short duv_http_minor(http_parser * parser) {
    return parser->http_minor;
}
unsigned int duv_http_status_code(http_parser * parser) {
    return parser->status_code;
}

size_t http_parser_url_size() {
    return sizeof(struct http_parser_url);
}

typedef struct {
    uint16_t off;
    uint16_t len;
} http_parser_url_field;

http_parser_url_field http_parser_get_field(struct http_parser_url * url, int field) {
    http_parser_url_field f;
    f.off = url->field_data[field].off;
    f.len = url->field_data[field].len;
    return f;
}

uint16_t http_parser_get_port(struct http_parser_url * url) {
    return url->port;
}

uint16_t http_parser_get_fieldset(struct http_parser_url * url) {
    return url->field_set;
}

uint64_t http_parser_get_content_length(http_parser * parser) {
    return parser->content_length;
}
