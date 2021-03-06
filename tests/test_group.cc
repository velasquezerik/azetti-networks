/*
 * Copyright (C) 2016 Azetti Networks
 */

#include <QtTest/QtTest>
#include "group.h"

std::string empty = "";
std::string uriPolice = "sip:police@example.com";
std::string uriMedics = "sip:medics@example.com";
std::string medics = "Medics";
std::string police = "Police";
std::string robert = "Robert";
std::string paramedics = "Paramedics";

class TestGroup : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase() {}
    void cleanupTestCase() {}

    /* Null object tests */

    void groupWithoutUriOrNameIsNull() {
        Group g;
        QCOMPARE(g.isNull(), true);
    }

    void groupWithEmptyUriAndNoNameIsNull() {
        Group g("");
        QCOMPARE(g.isNull(), true);
    }

    void groupWithEmptyUriAndNameIsNull() {
        Group g("", "");
        QCOMPARE(g.isNull(), true);
    }

    void groupWithUriAndNoNameIsNotNull() {
        Group g("sip:police@example.com");
        QCOMPARE(g.isNull(), false);
    }

    void groupWithUriAndNameIsNotNull() {
        Group g("sip:police@example.com", "Police");
        QCOMPARE(g.isNull(), false);
    }

    void nullGroupUriIsEmpty() {
        Group g;
        QCOMPARE(g.uri(), empty);
    }

    void nullGroupNameIsEmpty() {
        Group g;
        QCOMPARE(g.name(), empty);
    }

    void nullGroupStatusHasNoUsers() {
        Group g;
        QCOMPARE(g.count(), 0);
    }

    /* Ctor tests */

    void canInitUriWithCtorForeNamelessGroup() {
        Group g("sip:police@example.com");
        QCOMPARE(g.uri(), uriPolice);
    }

    void canInitUriWithCtorForNamedGroup() {
        Group g("sip:medics@example.com", "Medics");
        QCOMPARE(g.uri(), uriMedics);
    }

    void canInitNameWithCtor() {
        Group g("sip:medics@example.com", "Medics");
        QCOMPARE(g.name(), medics);
    }

    void initialNameForNamelessGroupIsEmpty() {
        Group g("sip:police@example.com");
        QCOMPARE(g.name(), empty);
    }

    void initialGroupCountIsZero() {
        Group g("sip:police@example.com");
        QCOMPARE(g.count(), 0);
    }

    /* Equal/not-eqaul operator tests */

    void nullGroupsAreEqual() {
        Group g1, g2;
        QVERIFY(g1 == g2);
    }

    void groupsAreEqualIfTheirUrisAreSame() {
        Group g1("sip:police@example.com");
        Group g2("sip:police@example.com");
        QVERIFY(g1 == g2);
    }

    void groupsAreEqualIfTheirUrisAreSameButNamesDiffer() {
        Group g1("sip:medics@example.com", "Medics");
        Group g2("sip:medics@example.com", "Robert");
        QVERIFY(g1 == g2);
    }

    void groupsAreNotEqualIfTheirUrisDiffer() {
        Group g1("sip:police@example.com");
        Group g2("sip:medics@example.com");
        QVERIFY(!(g1 == g2));
    }

    void groupsAreNotEqualIfTheirUrisDifferButNamesAreSame() {
        Group g1("sip:medics@example.com", "Robert");
        Group g2("sip:rob@example.com", "Robert");
        QVERIFY(!(g1 == g2));
    }

    /* Mutation tests */

    void cannotSetNullGroupName() {
        Group u;
        u.setName("Police");
        QCOMPARE(u.name(), empty);
    }

    void canChangeGroupNameIfWasUnset() {
        Group u("sip:police@example.com");
        u.setName("Police");
        QCOMPARE(u.name(), police);
    }

    void canChangeGroupNameIfWasSet() {
        Group u("sip:bob@example.com", "Bob");
        u.setName("Robert");
        QCOMPARE(u.name(), robert);
    }

    void cannotAddUserToNullGroup() {
        Group g;
        User u("sip:alice@example.com");
        g.add(u);
        QCOMPARE(g.count(), 0);
    }

    void cannotAddNullUserToGroup() {
        Group g("sip:police@example.com");
        User u;
        g.add(u);
        QCOMPARE(g.count(), 0);
    }

    void canAddOneUserToGroup() {
        Group g("sip:police@example.com");
        User u("sip:alice@example.com");
        g.add(u);
        QCOMPARE(g.count(), 1);
    }

    void canAddTwoUsersWithUniqueUriToGroup() {
        Group g("sip:police@example.com", "Police");
        User u1("sip:alice@example.com", "Alice");
        User u2("sip:bob@example.com", "Bob");
        g.add(u1);
        g.add(u2);
        QCOMPARE(g.count(), 2);
    }

    void cannotAddTwoUsersWithSameUriToGroup() {
        Group g("sip:police@example.com", "Police");
        User u1("sip:bob@example.com", "Bob");
        User u2("sip:bob@example.com", "Robert");
        g.add(u1);
        g.add(u2);
        QCOMPARE(g.count(), 1);
    }

    void cannotAddSameUserToGroupTwice() {
        Group g("sip:police@example.com", "Police");
        User u("sip:bob@example.com", "Bob");
        g.add(u);
        g.add(u);
        QCOMPARE(g.count(), 1);
    }

    void canRemoveMemberFromGroup() {
        Group g("sip:police@example.com", "Police");
        User u("sip:bob@example.com", "Bob");
        g.add(u);
        g.remove(u);
        QCOMPARE(g.count(), 0);
    }

    void removingNonMemberFromGroupIsNop1() {
        Group g("sip:police@example.com", "Police");
        User u("sip:bob@example.com", "Bob");
        g.remove(u);
        QCOMPARE(g.count(), 0);
    }

    void removingNonMemberFromGroupIsNop2() {
        Group g("sip:police@example.com", "Police");
        User u1("sip:alice@example.com", "Alice");
        User u2("sip:bob@example.com", "Bob");
        g.add(u1);
        g.remove(u2);
        QCOMPARE(g.count(), 1);
    }

    void groupContainesAddedUser() {
        Group g("sip:police@example.com", "Police");
        User u("sip:bob@example.com", "Bob");
        g.add(u);
        QCOMPARE(g.contains(u), true);
    }

    void groupDoesntContainNotAddedUser() {
        Group g("sip:police@example.com", "Police");
        User u("sip:bob@example.com", "Bob");
        QCOMPARE(g.contains(u), false);
    }

    /* Copy tests */

    void copyOfGroupHasSameUri() {
        Group g1("sip:police@example.com");
        Group g2 = g1;
        QCOMPARE(g2.uri(), uriPolice);
    }

    void copyOfGroupHasSameName() {
        Group g1("sip:medics@example.com", "Medics");
        Group g2 = g1;
        QCOMPARE(g2.name(), medics);
    }

    void copyOfGroupSharesName1() {
        Group g1("sip:medics@example.com", "Medics");
        Group g2 = g1;
        g1.setName("Paramedics");
        QCOMPARE(g2.name(), paramedics);
    }

    void copyOfGroupSharesName2() {
        Group g1("sip:medics@example.com", "Medics");
        Group g2 = g1;
        g2.setName("Robert");
        QCOMPARE(g1.name(), robert);
    }

    void copyOfGroupSharesUsers1() {
        Group g1("sip:police@example.com");
        Group g2;
        User u1("sip:alice@example.com");
        User u2("sip:bob@example.com");
        g1.add(u1);
        g2 = g1;
        g1.add(u2);
        QCOMPARE(g2.count(), 2);
    }

    void copyOfGroupSharesUsers2() {
        Group g1("sip:police@example.com");
        Group g2;
        User u1("sip:alice@example.com");
        User u2("sip:bob@example.com");
        g1.add(u1);
        g2 = g1;
        g2.add(u2);
        QCOMPARE(g1.count(), 2);
    }

    /* Group as contact tests */

    void contactFromGroupHasSameUri() {
        Group g("sip:police@example.com");
        Contact &c = g;
        QCOMPARE(c.uri(), uriPolice);
    }

    void contactFromGroupHasSameName() {
        Group g("sip:Police@example.com", "Police");
        Contact &c = g;
        QCOMPARE(c.name(), police);
    }

    void contactFromGroupSharesName1() {
        Group g("sip:medics@example.com", "Medics");
        Contact &c = g;
        g.setName("Paramedics");
        QCOMPARE(c.name(), paramedics);
    }

    void contactFromGroupSharesName2() {
        Group g("sip:medics@example.com", "Medics");
        Contact &c = g;
        c.setName("Paramedics");
        QCOMPARE(g.name(), paramedics);
    }
};

QTEST_MAIN(TestGroup);
#include "test_group.moc"
