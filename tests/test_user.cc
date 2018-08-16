/*
 * Copyright (C) 2016 Azetti Networks
 */

#include <QtTest/QtTest>
#include "user.h"

std::string empty = "";
std::string uriAlice = "sip:alice@example.com";
std::string uriBob = "sip:bob@example.com";
std::string bob = "Bob";
std::string alice = "Alice";
std::string robert = "Robert";

class TestUser : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase() {}
    void cleanupTestCase() {}

    /* Null object tests */

    void userWithoutUriOrNameIsNull() {
        User u;
        QCOMPARE(u.isNull(), true);
    }

    void userWithEmptyUriAndNoNameIsNull() {
        User u("");
        QCOMPARE(u.isNull(), true);
    }

    void userWithEmptyUriAndNameIsNull() {
        User u("", "");
        QCOMPARE(u.isNull(), true);
    }

    void userWithUriAndNoNameIsNotNull() {
        User u("sip:alice@example.com");
        QCOMPARE(u.isNull(), false);
    }

    void userWithUriAndNameIsNotNull() {
        User u("sip:alice@example.com", "Alice");
        QCOMPARE(u.isNull(), false);
    }

    void nullUserUriIsEmpty() {
        User u;
        QCOMPARE(u.uri(), empty);
    }

    void nullUserNameIsEmpty() {
        User u;
        QCOMPARE(u.name(), empty);
    }

    void nullUserStatusIsUnknown() {
        User u;
        QCOMPARE(u.status(), User::Status::UNKNOWN);
    }

    /* Ctor tests */

    void canInitUriWithCtorForeNamelessUser() {
        User u("sip:alice@example.com");
        QCOMPARE(u.uri(), uriAlice);
    }

    void canInitUriWithCtorForNamedUser() {
        User u("sip:bob@example.com", "Bob");
        QCOMPARE(u.uri(), uriBob);
    }

    void canInitNameWithCtor() {
        User u("sip:bob@example.com", "Bob");
        QCOMPARE(u.name(), bob);
    }

    void initialNameForNamelessUserIsEmpty() {
        User u("sip:alice@example.com");
        QCOMPARE(u.name(), empty);
    }

    void initialUserStatusIsUnknown() {
        User u("sip:alice@example.com");
        QCOMPARE(u.status(), User::Status::UNKNOWN);
    }

    /* Equal/not-eqaul operator tests */

    void nullUsersAreEqual() {
        User u1, u2;
        QVERIFY(u1 == u2);
    }

    void usersAreEqualIfTheirUrisAreSame() {
        User u1("sip:alice@example.com");
        User u2("sip:alice@example.com");
        QVERIFY(u1 == u2);
    }

    void usersAreEqualIfTheirUrisAreSameButNamesDiffer() {
        User u1("sip:bob@example.com", "Bob");
        User u2("sip:bob@example.com", "Robert");
        QVERIFY(u1 == u2);
    }

    void usersAreNotEqualIfTheirUrisDiffer() {
        User u1("sip:alice@example.com");
        User u2("sip:bob@example.com");
        QVERIFY(!(u1 == u2));
    }

    void usersAreNotEqualIfTheirUrisDifferButNamesAreSame() {
        User u1("sip:bob@example.com", "Robert");
        User u2("sip:rob@example.com", "Robert");
        QVERIFY(!(u1 == u2));
    }

    /* Mutation tests */

    void cannotSetNullUserName() {
        User u;
        u.setName("Alice");
        QCOMPARE(u.name(), empty);
    }

    void cannotSetNullUserStatus() {
        User u;
        u.setStatus(User::Status::ONLINE);
        QCOMPARE(u.status(), User::Status::UNKNOWN);
    }

    void canChangeUserNameIfWasUnset() {
        User u("sip:alice@example.com");
        u.setName("Alice");
        QCOMPARE(u.name(), alice);
    }

    void canChangeUserNameIfWasSet() {
        User u("sip:bob@example.com", "Bob");
        u.setName("Robert");
        QCOMPARE(u.name(), robert);
    }

    void canChangeUserStatusToOffline() {
        User u("sip:alice@example.com");
        u.setStatus(User::Status::OFFLINE);
        QCOMPARE(u.status(), User::Status::OFFLINE);
    }

    void canChangeUserStatusToOnline() {
        User u("sip:alice@example.com");
        u.setStatus(User::Status::ONLINE);
        QCOMPARE(u.status(), User::Status::ONLINE);
    }

    /* Copy tests */

    void copyOfUserHasSameUri() {
        User u1("sip:alice@example.com");
        User u2 = u1;
        QCOMPARE(u2.uri(), uriAlice);
    }

    void copyOfUserHasSameName() {
        User u1("sip:bob@example.com", "Bob");
        User u2 = u1;
        QCOMPARE(u2.name(), bob);
    }

    void copyOfUserSharesName1() {
        User u1("sip:bob@example.com", "Bob");
        User u2 = u1;
        u1.setName("Robert");
        QCOMPARE(u2.name(), robert);
    }

    void copyOfUserSharesName2() {
        User u1("sip:bob@example.com", "Bob");
        User u2 = u1;
        u2.setName("Robert");
        QCOMPARE(u1.name(), robert);
    }

    void copyOfUserSharesStatus1() {
        User u1("sip:alice@example.com");
        User u2 = u1;
        u1.setStatus(User::Status::ONLINE);
        QCOMPARE(u2.status(), User::Status::ONLINE);
    }

    void copyOfUserSharedStatus2() {
        User u1("sip:alice@example.com");
        User u2 = u1;
        u2.setStatus(User::Status::ONLINE);
        QCOMPARE(u1.status(), User::Status::ONLINE);
    }

    /* User as contact tests */

    void contactFromUserHasSameUri() {
        User u("sip:alice@example.com");
        Contact &c = u;
        QCOMPARE(c.uri(), uriAlice);
    }

    void contactFromUserHasSameName() {
        User u("sip:bob@example.com", "Bob");
        Contact &c = u;
        QCOMPARE(c.name(), bob);
    }

    void contactFromUserSharesName1() {
        User u("sip:bob@example.com", "Bob");
        Contact &c = u;
        u.setName("Robert");
        QCOMPARE(c.name(), robert);
    }

    void contactFromUserSharesName2() {
        User u("sip:bob@example.com", "Bob");
        Contact &c = u;
        c.setName("Robert");
        QCOMPARE(u.name(), robert);
    }
};

QTEST_MAIN(TestUser);
#include "test_user.moc"
