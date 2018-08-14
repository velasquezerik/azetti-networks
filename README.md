=================================
 Azetti Networks - C++ Test Case
=================================

Set of classes for contacts
===========================

You are working on an mobile application for text messaging, similar
to WhatsApp, Telegram, Facebook Messenger, etc. Propose and implement
a set of classes to represent contacts from the contact list in the
app. There are two kinds of contacts:
(i) users which you chat with individually, and
(ii) groups (aka named chat rooms) where multiple users chat together.

The interface requirements for your classes are defined by a test
suite comprising test_user.cc and test_groups.cc modules. You can
extend the test suite as needed but you should not modify existing
tests.

Restrictions
============

Your solution should follow the C++11 standard and you are allowed to
use Qt5 software toolkit in addition to the standard library. Where
possible, prefer the Qt library to the C++ standard library.

Library classes should be implemented using D-Pointer (PIMPL) approach.

Your code has to be easy readable to the others.


Quick start
===========

Modify CMakeLists.txt file to add any new modules to the project.

To compile your code execute::

  cmake .
  make

To run the tests execute::

  make test # or ctest
  make test CTEST_OUTPUT_ON_FAILURE=1  # or ctest --verbose
