#include <QtTest>
#include <QString>
#include <QList>
#include <QDebug>
#include <QClipboard>
#include <QTimer>
#include <com/http.h>
#include <com/script.h>
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
    void test18();
    void test19();
    void test20();
    void test21();
    void test22();
    void test23();
    void test24();
    void test25();
    void testRegular();
    void testParser1();
    void testParser2();
    void testParser3();
    void testParser4();
    void testParser5();
    void testParser6();
    void testParser7();
    void testParser8();
    void testParser9();
    void testParser10();
    void testParser11();
    void testParser12();
};

xxmoonTest::xxmoonTest(){
}

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
    QString src = "System.out.Println(\"hello world!\");";
    QString code = "java";
    qDebug() << src.toUtf8().data();
    QString x = Highlight(src.toUtf8().data(), code.toUtf8().data());
    ut::file::writeText("E:/code_java.html", x);
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

void xxmoonTest::testParser1() {
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
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>c</h1><p style='line-height:20px'>&nbsp;</p><h1>b</h1>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[1], expe1);

    s = "a\nhttp://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<div><a href='http://b'>http://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\n\n```\nb\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><p style='line-height:20px'>&nbsp;</p>\";width:parent?parent.width:0}";
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
    expe0 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2021/20210828162625.433.500.333.png\";width:Math.min(parent?parent.width:0,500);height:333;scale:1}";
    QCOMPARE(qmls[0], expe0);

    s = "a\n!(2021/20210828162625.433.500.333.png)";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<br>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2021/20210828162625.433.500.333.png\";width:Math.min(parent?parent.width:0,500);height:333;scale:1}";
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
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='line-height:20px'>&nbsp;</p><h1>b</h1>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[1], expe1);

    s = "!(2023/20231010090004.712.430.196.png)\n```\na\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2023/20231010090004.712.430.196.png\";width:Math.min(parent?parent.width:0,430);height:196;scale:1}";
    QCOMPARE(qmls[0], expe0);
    expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[1], expe1);

    s = "file://1.mp4";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><div><a href='file://1.mp4'>file://1.mp4</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "```\na\n```\n```\nb\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);

    s = "```\na\n```\n\n# b\n\n# c\n\nd\n\ne";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='line-height:20px'>&nbsp;</p><h1>b</h1><p style='line-height:20px'>&nbsp;</p><h1>c</h1><p style='line-height:20px'>&nbsp;</p>d<br><br>e\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);

    //横线 ------------- start
    s = "a\n----\nb";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<hr>b\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\n----\n";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><p style='line-height:20px'>&nbsp;</p><hr>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "----\nx";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><hr>x\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\n\n----\n";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><p style='line-height:20px'>&nbsp;</p><hr>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "a\n----\nb\n----";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<hr>b<hr>\";width:parent?parent.width:0}";
    Q_ASSERT(qmls.size() == 1);
    QCOMPARE(qmls[0], expe0);

    s = "-----------------\n";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>-----------------<br>\";width:parent?parent.width:0}";
    Q_ASSERT(qmls.size() == 1);
    QCOMPARE(qmls[0], expe0);

    s = "----\n";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><hr>\";width:parent?parent.width:0}";
    Q_ASSERT(qmls.size() == 1);
    QCOMPARE(qmls[0], expe0);
    //横线 ------------- end

    // s = "aaaaaaaaaaaaaaa\n!(2021/20210828162625.433.500.333.png)\nbbbbbbbbbbbbbbb";
    // qmls = doc_parser->parseQML(s, 600);

    // s = "!(2024/20240604082742.397.864.1795.png)";
    // qmls = doc_parser->parseQML(s, 600);

    QString expe2;
    s = "```\na\n```\n\n```\nb\n```";
    qmls = doc_parser->parseQML(s, 600);
    QCOMPARE(qmls.size(), 3);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='line-height:20px'>&nbsp;</p>\";width:parent?parent.width:0}";
    expe2 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
    QCOMPARE(qmls[2], expe2);

    s = "a\n!(2021/20210828162625.433.500.333.png)\n\nb";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 3);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<br>\";width:parent?parent.width:0}";
    expe1 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2021/20210828162625.433.500.333.png\";width:Math.min(parent?parent.width:0,500);height:333;scale:1}";
    expe2 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='line-height:20px'>&nbsp;</p>b\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
    QCOMPARE(qmls[2], expe2);

    // for(QString& qml:qmls) {
    //     qDebug() << qml;
    // }
}

void xxmoonTest::testParser2() {
    // 测试：图片、空行、标题、文本、分隔线、代码块
    // !(2024/20240604105236.694.488.353.png)
    //
    // # a
    // b
    // ----
    // ```
    // c
    // ```
    QString s = "!(2024/20240604105236.694.488.353.png)\n\n# a\nb\n----\n```\nc\n```";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 3);

    // 验证图片组件 - 包含图片路径和尺寸信息
    QString expe0 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2024/20240604105236.694.488.353.png\";width:Math.min(parent?parent.width:0,488);height:353;scale:1}";
    QString expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><p style='line-height:20px'>&nbsp;</p><h1>a</h1>b<hr>\";width:parent?parent.width:0}";
    QString expe2 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>c\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
    QCOMPARE(qmls[2], expe2);
}

void xxmoonTest::testParser3() {
    QString s = "# a\n\n----";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);

    // 验证标题和分隔线 - # 前面有空格所以不会被解析成标题
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><p style='line-height:20px'>&nbsp;</p><hr>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
}

void xxmoonTest::testParser4() {
    QString s = "# a\n\n```\nb\n```";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);

    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><p style='line-height:20px'>&nbsp;</p>\";width:parent?parent.width:0}";
    QString expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
}

void xxmoonTest::testParser5() {
    QString s = "```\na\n```\n!(2024/20240604105236.694.488.353.png)";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);

    QString expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QString expe1 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2024/20240604105236.694.488.353.png\";width:Math.min(parent?parent.width:0,488);height:353;scale:1}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
}

void xxmoonTest::testParser6() {
    QString s = "http://a\nhttps://b";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);

    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><div><a href='http://a'>http://a</a></div><div><a href='https://b'>https://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
}
void xxmoonTest::testParser7() {
    QString s = "a\n```\nb\n```";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);

    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0}";
    QString expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
}

void xxmoonTest::testParser8() {
    QString s = "!(2026/20260602143514.182.2732.1534.png)\na";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);

    QString expe0 = "Img{src:\"file:///D://xxmoon/xxmoon/imgs/2026/20260602143514.182.2732.1534.png\";width:Math.min(parent?parent.width:0,2732);height:1534;scale:1}";
    QString expe1 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
}
void xxmoonTest::testParser9() {
    QString s = "xxx\n```java\nSystem.out.Println(\"hello world!\");\n```\na";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 3);
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>xxx\";width:parent?parent.width:0}";
    QString expe1 = "Code{text:'";
    QString expe2 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    Q_ASSERT(qmls[1].startsWith(expe1));
    QCOMPARE(qmls[2], expe2);
}
void xxmoonTest::testParser10() {
    QString s = "# a\nhttp://b";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><div><a href='http://b'>http://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "## a\nhttp://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h2>a</h2><div><a href='http://b'>http://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "### a\nhttp://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h3>a</h3><div><a href='http://b'>http://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\nhttps://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><div><a href='https://b'>https://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\nfile://b";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><div><a href='file://b'>file://b</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
}
void xxmoonTest::testParser11() {
    QString s = "# a\nb\n```\nc\n```";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1>b\";width:parent?parent.width:0}";
    QString expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>c\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
}
void xxmoonTest::testParser12() {
    QString s = "# a\n## b\n### c";
    QStringList qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    QString expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><h2>b</h2><h3>c</h3>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
}
void xxmoonTest::test18() {
    QString k = "#hello!(x)$";
    filterSearchKey(k);
    QCOMPARE(k, "#hellox");
    // qDebug() << k;
}

//搜索关键词高亮
void xxmoonTest::test19() {
    QString s = "xxx\n```java\nxxxo world!\n```\naaa";
    QString k = "xx a";
    s = extractXMSimpleCont(s, k);
    QCOMPARE(s, "@#red xx@x\n```java\nxxxo world!\n```\n@#red a@aa");

    s = "mac命令定时";
    k = "mac 定时";
    s = extractXMSimpleCont(s, k);
    QCOMPARE(s, "@#red mac@命令@#red 定时@");
}

//调用python
void xxmoonTest::test20() {
    // a->initCfg();
    // Script::INS().exeCmd(1, "check_douyin_live.py", "");
    QProcess process;
    // process.start("/usr/local/bin/python3", QStringList() << "/Volumes/MD/xxmoon/xxmoon/scripts/check_douyin_live.py");
    // QString script = "/Volumes/MD/xxmoon/xxmoon/scripts/img_size.py";
    // QString p1 = "/Volumes/MD/xxmoon/xxmoon/imgs/2024/20240604082742.397.864.1795.png";
    // QString p2 = "0.5";
    QString script = "D:\\xxmoon\\xxmoon\\scripts\\check_live.py";
//    QString p1 = "senlinmuvs";
//    QString p2 = "200";
    process.start("python", QStringList() << script);
    if(process.waitForStarted()) {
        if(process.waitForFinished()) {
            QString out = process.readAll();
            qDebug() << out;
        } else {
            qDebug() << "err1" << process.errorString();
        }
    } else {
        qDebug() << "err2" << process.errorString();
    }
}

//定时器文件同步
void xxmoonTest::test21() {
    a->initCfg();
    // QMap<QString, qint64> m;
    // m["a"] = 10;
    // m["/Volumes/MD/xxmoon/xxmoon/attaches/important.txt"] = 11;
    // qDebug() << m.value("a");
    // qDebug() << m["a"];
    // qDebug() << m.value("/Volumes/MD/xxmoon/xxmoon/attaches/important.txt");
    qint64 t1 = ut::time::getCurMills();
    QList<QStringList> arr = sy->getUploadFiles();
    QStringList list = arr[0];
    qint64 t2 = ut::time::getCurMills();
    qDebug() << t2 - t1;
    //[check_live.py:10000]
    QString f1 = cfg->scriptDir+"/check_live.py";
    QString f2 = cfg->scriptDir+"/_check_live.py";
    qint64 f1Time = sy->valueOfFileMod(f1);
    Q_ASSERT(f1Time > 0);

    ut::file::rename(f1, f2);
    arr = sy->getUploadFiles();
    list = arr[0];
    //[_check_live.py:10000]
    Q_ASSERT(list.size() == 1);
    QCOMPARE(list.at(0), f2);
    f1Time = sy->valueOfFileMod(f1);
    qint64 f2Time = sy->valueOfFileMod(f2);
    Q_ASSERT(f1Time == 0);
    Q_ASSERT(f2Time > 0);

    ut::file::rename(f2, f1);
    arr = sy->getUploadFiles();
    list = arr[0];
    Q_ASSERT(list.size() == 1);
    QCOMPARE(list.at(0), f1);
    f1Time = sy->valueOfFileMod(f1);
    f2Time = sy->valueOfFileMod(f2);
    Q_ASSERT(f1Time > 0);
    Q_ASSERT(f2Time == 0);
}

void xxmoonTest::test22() {
    QString cont = "<每隔1分,1,x.py>";
    QString r = "成功";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "成功";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "成功";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "yyy";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "yyy";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "yyy";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    r = "yyy";
    Script::INS().updateStatusText(cont, r);
    qDebug() << cont;

    // int i = cont.lastIndexOf("\n----\n");
    // if(i >= 0) {
    //     cont = cont.mid(0, i);
    // }
    // qDebug() << cont;
}

void xxmoonTest::test23() {
    lg->init(cfg->logFile);
    cfg->logLevel = "info";
    // lg->info("hello", "world", "xxx", "alksdjf");
}

void xxmoonTest::test24() {
    QString s = "a\n----\nb\n----\n";
            // s = "a\n----\nb\n----";
    qDebug() << s;
    // s = ut::str::replaceAllTag(s, "----","\n", "<hr>", "");
    s = s.replace("----\n", "<hr>");
    qDebug() << s;
}

//判断是否是中文
void xxmoonTest::test25() {
    // QChar::UnicodeVersion v = QChar::currentUnicodeVersion();
    // qDebug() << v << QChar::UnicodeVersion::Unicode_15_0;
    QString s = "哈abc*&^喽鿿";
    for(int i = 0; i < s.length(); i++) {
        // if(ut::str::isChinese(s[i])) {
            qDebug() << s[i];
        // }
    }
}

void xxmoonTest::testRegular() {
    static QRegularExpression re("\n[#]{1,3}[ ].+\n.+", QRegularExpression::DotMatchesEverythingOption);
    QString s = "\n# xxx\nasldfjsldf";
    QRegularExpressionMatch match = re.match(s);
    Q_ASSERT(match.hasMatch() == true);

    s = "\n## xxx\n\nasld\nfjsldf";
    match = re.match(s);
    Q_ASSERT(match.hasMatch() == true);

    s = "\n### \nsdf\nasld\nfjsldf";
    match = re.match(s);
    Q_ASSERT(match.hasMatch() == true);
}

QTEST_APPLESS_MAIN(xxmoonTest)

#include "tst_xxmoontest.moc"
