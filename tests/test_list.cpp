/* -*- c++ -*- */
/*
 * Copyright (C) 2010 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "../include/list"
#ifndef ANDROID_ASTL_LIST__
#error "Wrong header included!!"
#endif
#include <string>
#include "common.h"

namespace android {
using std::list;
using std::string;

bool testConstructor()
{
    list<int> list1;
    list<int*> list2;
    list<string> list3;
    list<B> list4;
    return true;
}

bool testClear()
{
    {
        list<int> l;
        for (int i = 0; i < 100; ++i) {
            l.push_front(i);
            l.push_back(i);
        }
        l.clear();
        EXPECT_TRUE(l.size() == 0);
        EXPECT_TRUE(l.empty());
    }
    {
        list<B> l;
        for (int i = 0; i < 10; ++i) {
            l.push_front(B());
            l.push_back(B());
        }
        l.clear();
        EXPECT_TRUE(l.size() == 0);
        EXPECT_TRUE(l.empty());
    }
    return true;
}
bool testSize()
{
    list<int> list;

    EXPECT_TRUE(list.size() == 0);
    EXPECT_TRUE(list.empty());

    list.push_front(1);
    EXPECT_TRUE(list.size() == 1);
    EXPECT_FALSE(list.empty());

    for (int i = 0; i < 10; ++i) {
        list.push_front(1);
        list.push_back(1);
    }
    EXPECT_TRUE(list.size() == 21);
    return true;
}

bool testIterator()
{
    list<int> l;
    for (int i = 0; i < 100; ++i) {
        l.push_back(i);
    }

    list<int>::const_iterator it = l.begin();
    for (int i = 0; it != l.end(); ++it, ++i) {
        EXPECT_TRUE(*it == i);
    }

    l.clear();
    for (int i = 0; i < 100; ++i) {
        l.push_front(i);
    }

    it = l.begin();
    for (int i = 99; it != l.end(); ++it, --i) {
        EXPECT_TRUE(*it == i);
    }

    return true;
}

}  // namespace android

int main(int argc, char **argv)
{
    FAIL_UNLESS(testConstructor);
    FAIL_UNLESS(testSize);
    FAIL_UNLESS(testClear);
    FAIL_UNLESS(testIterator);
    return kPassed;
}
