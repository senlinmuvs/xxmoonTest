#include <QtTest>
#include <QString>
#include <QList>
#include <QDebug>
#include <QClipboard>
#include <QTimer>
#include <com/http.h>
#include "com/util.h"
#include "com/global.h"
#include "com/docparser.h"
#include "libxxmoon.h"

class xxmoonTest : public QObject {
    Q_OBJECT

public:
    xxmoonTest();
    ~xxmoonTest();

private slots:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    void test9();
    void test10();
    void test11();
    void test12();
    void test13();
    void test14();
    void test15();
    void test16();
    void test17();
};

xxmoonTest::xxmoonTest() {}

xxmoonTest::~xxmoonTest() {}

void xxmoonTest::test1() {
    QString s = ut::file::readFile("/Volumes/D/x.txt");
    //    qDebug() << s;
    QList<DocParser::DocTag> tags;
    tags << DocParser::DocTag::create(DocParser::TY_QUOTE);
    tags << DocParser::DocTag::create(DocParser::TY_IMG);
    QList<QString> l;
    int start = 0;
    while(true) {
        int i0 = -1;
        int i1 = -1;
        int tagsIndex = 0;
        for(int i = 0; i < tags.size(); i++) {
            DocParser::DocTag dt = tags.at(i);
            int i0_ = s.indexOf(dt.tag0, start);
            if(i0_ >= 0) {
                int i1_ = s.indexOf(dt.tag1, i0_+dt.tag0.size());
                if(i1_ >= 0) {
                    if((i0 < 0 || i0_ < i0) && (i1 < 0 || i1_ < i1)) {
                        i0 = i0_;
                        i1 = i1_;
                        tagsIndex = i;
                    }
                }
            }
        }

        //        DocParser::DocTag textDocTag = DocParser::DocTag(DocParser::TY_TEXT);
        //        if(i0 >= 0 && i1 >= 0) {
        //            if(i0 > start) {
        //                l << DocParser::Doc(textDocTag.ty, s.mid(start, i0-start)).parse();
        //            }
        //            //
        //            DocParser::DocTag dt = tags.at(tagsIndex);
        //            int tag0Len = dt.tag0.length();
        //            int tag1Len = dt.tag1.length();
        //            if(i1 > i0+tag0Len) {
        //                l << DocParser::Doc(dt.ty,s.mid(i0+tag0Len, i1-i0-tag0Len)).parse();
        //            }
        //            //
        //            if(i1 + tag1Len > start) {
        //                start = i1 + tag1Len;
        //            }
        //            qDebug() << start << i0 << i1;
        //        } else {
        //            if(s.size()-1 > start) {
        //                l << DocParser::Doc(textDocTag.ty,s.right(s.size() - start)).parse();
        //            }
        //            break;
        //        }
    }
    //
    for(QString s:l) {
        qDebug() << s;
    }
}

void xxmoonTest::test2() {
    QString s = ut::file::readFile("/Volumes/D/x.txt");
    DocParser dp;
    QStringList l = dp.parseQML(s);
    for(QString s : l) {
        qDebug() << s;
    }
}

void xxmoonTest::test3() {
    QString img = "x.gifx";
    int ty = ut::file::postfixType(img);
    QByteArray ba;
    char c = (char)ty;
    ba.append(c);
    int ty_ = (int)ba.at(0);
    qDebug() << ty << "|" << ty_ << ba.size();
}

void xxmoonTest::test4() {
    QString img = "20210215224724.361.1920.1080.png";
    std::tuple<uint, uint> tp = getWHFromFileName(img);
    qDebug() << get<0>(tp) << get<1>(tp);
}

void xxmoonTest::test5() {
    // QString src = ut::file::readFile("/Users/sen/Desktop/src.txt");
    QString src = "//aaa";
    QString code = "java";
    qDebug() << src.toUtf8().data();
    QString x = Highlight(src.toUtf8().data(), code.toUtf8().data());
    ut::file::writeText("/Users/sen/Desktop/code_java.html", x);
    qDebug() << x;
}
void xxmoonTest::test6() {
    //    doc_parser->test();
    QString s = "````\nx`````\n";
    qDebug() << s;
    //    s = ut::str::replaceAllTag(s, "`# ","\n", "# ", "\n");
    //    s = s.replace("``", "`");
    //    s = ut::str::replaceAllTag(s, "`","\n", "", "\n");
    s = ut::str::replaceAllTag(s, "```","```\n", "<", ">");
    qDebug() << s;
}
void xxmoonTest::test7() {
    QString cont = ut::file::readFile("/Users/sen/Desktop/x");
    //    qDebug() << cont.toUtf8().data();
    QString html = doc_parser->parseHtml(cont, 600);
    qDebug() << html.toUtf8().data();
    QStringList qmls = doc_parser->parseQML(cont, 600);
    for(int i = 0; i < qmls.length(); i++) {
        qDebug() << qmls.at(i).toUtf8().data();
    }
}
void xxmoonTest::test8() {
    QString param = QString::number(800);
    //    QString s = "**a\nx**";
    //    QString s = "**a**";
    //    s = ut::str::replaceAllTag(s, "**","**", "<b>", "</b>", 1, param, "\n", eachTag_);

    //    QString s = "@#a@";
    QString s = "**a\nb**";
    s = ut::str::replaceAllTag(s, "**","**", "<b>", "</b>", 1, param, "\n", nullptr);
    qDebug() << s;
}
void xxmoonTest::test9() {
    QString s = "# a\n```\nb\n```";
    //    QString s = "a\nhttp://b";
    //    QString html = doc_parser->parseHtml(s, 600);
    //    qDebug() << html.toUtf8().data();
    QStringList qmls = doc_parser->parseQML(s, 600);
    for(int i = 0; i < qmls.length(); i++) {
        qDebug() << qmls.at(i).toUtf8().data();
    }
}

void xxmoonTest::test10() {
    QString cont = ut::file::readFile("/Users/sen/Desktop/cont.txt");
    QStringList list = extractImgsAsList(cont);
    qDebug() << list;
}

void xxmoonTest::test11() {
    QClipboard *board = QGuiApplication::clipboard();
    QObject::connect(board, &QClipboard::dataChanged, a, [=](){
            static bool finished = true;

            qDebug() << "datachanged:" <<  board->text();

            if(board->text() == "" || finished == false) {
                return;
            }

            QString text = board->text();
            text = text.replace("\n", "\t");

            qDebug() << "new text:" << text;

            finished = false;
            board->setText(text);
            finished = true;
        }, Qt::DirectConnection);
}

void xxmoonTest::test12() {
    DB_Async->exe("test1", []{
        qDebug() << "test1 task doing";
    });
    DB_Async->exe("test2", []{
        qDebug() << "test2 task doing";
    });
    DB_Async->exe("test3", []{
        qDebug() << "test3 task doing";
    });
    DB_Async->exe("test4", []{
        lg->debug("test4 task doing");
        QThread::msleep(2000);
        lg->debug("test4 task end");
    });
    DB_Async->exe("test5", []{
        qDebug() << "test5 task doing";
    });
}
void xxmoonTest::test13() {
    QMap<QString, QString> params;
    params["path"] = "";
    params["cid"] = "0";
    params["user"] = "xxmoon";
    params["pwd"] = "12345";
    Http *http = new Http();
    http->upload("https://localhost/upfile", params, "/Volumes/MD/CodeCharts12.pdf", [http]{
            qDebug() << "done";
            http->deleteLater();
        }, [](qint64 s, qint64 t){
            qDebug() << ">" << s << t;
        });
}
void xxmoonTest::test14() {
    QMap<QString, QString> params;
    params["path"] = "";
    params["cid"] = "0";
    params["user"] = "xxmoon";
    params["pwd"] = "12345";
    QString file = "/Volumes/MD/pobi.png";
    QEventLoop loop;
    Http http;
    http.upload("https://localhost/upfile", params, file, [file, &loop]{
            qDebug() << "done" << file;
            loop.quit();
            qDebug() << "done>>>>>>>>>";
        }, [](qint64 s, qint64 t) {
            qDebug() << ">" << s << t;
        });
    loop.exec();
}

void xxmoonTest::test15() {
    QEventLoop eventLoop;
    QTimer::singleShot(3000, &eventLoop, [&eventLoop]{
        eventLoop.quit();
    });
    // QTimer::singleShot(3000, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
    qDebug() << "Event loop finished. Continuing execution...";
}

void xxmoonTest::test16() {
    QMap<QString, QString> params;
    QEventLoop loop;
    Http http;
    http.timeout = 2000;
    qDebug() << "post timeout" << http.timeout;
    http.post("https://localhost/test", params, [&](QJsonObject& jo){
            qDebug() << "resp" << jo;
            loop.quit();
        }, [&](QNetworkReply::NetworkError err){
            qDebug() << "err" << err;
            loop.quit();
        });
    loop.exec();
}

void xxmoonTest::test17() {
    QString s = "# a\n```\nb\n```";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    QString expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[1], expe1);

    s = "```\na\n```\n# c\n\n\n# b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>c</h1><br><br><h1>b</h1>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[1], expe1);

    s = "a\nhttp://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<div><a href='http://b'>http://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\n\n```\nb\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><br>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[1], expe1);

    s = "```\na\n```\nb";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0}";
    QCOMPARE(qmls[1], expe1);

    s = "!(2021/20210828162625.433.500.333.png)";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Img{src:\"file:///Users/sen/xxmoon/xxmoon/imgs/2021/20210828162625.433.500.333.png\";width:Math.min(parent?parent.width:0, 500);height:333}";
    QCOMPARE(qmls[0], expe0);

    s = "a\n!(2021/20210828162625.433.500.333.png)";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Img{src:\"file:///Users/sen/xxmoon/xxmoon/imgs/2021/20210828162625.433.500.333.png\";width:Math.min(parent?parent.width:0, 500);height:333}";
    QCOMPARE(qmls[1], expe1);

    s = ":[a]\nb";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='color:gray;text-align: right;font-style: italic;'>a</p>b\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "```\na\n```\n\n# b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><br><h1>b</h1>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[1], expe1);

    s = "!(2023/20231010090004.712.430.196.png)\n```\na\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Img{src:\"file:///Users/sen/xxmoon/xxmoon/imgs/2023/20231010090004.712.430.196.png\";width:Math.min(parent?parent.width:0, 430);height:196}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[1], expe1);
    // for(QString qml:qmls) {
    //     qDebug() << qml;
    // }
}

QTEST_APPLESS_MAIN(xxmoonTest)

#include "tst_xxmoontest.moc"
