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
    void test17();
    void test18();
    void test19();
    void test20();
    void test21();
    void test22();
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

    s = "xxx\n```java\nhello world!\n```\na";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 3);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>xxx\";width:parent?parent.width:0}";
    expe1 = "Code{text:'<style type=\"text/css\">\n/* Background */ .chroma {  }\n/* Error */ .chroma .err { color: #000000 }\n/* LineTableTD */ .chroma .lntd { vertical-align: top; padding: 0; margin: 0; border: 0; }\n/* LineTable */ .chroma .lntable { border-spacing: 0; padding: 0; margin: 0; border: 0; width: auto; overflow: auto; display: block; }\n/* LineHighlight */ .chroma .hl { display: block; width: 100%;background-color: #e5e5e5 }\n/* LineNumbersTable */ .chroma .lnt { margin-right: 0.4em; padding: 0 0.4em 0 0.4em;color: #7f7f7f }\n/* LineNumbers */ .chroma .ln { margin-right: 0.4em; padding: 0 0.4em 0 0.4em;color: #7f7f7f }\n/* Keyword */ .chroma .k { color: #a90d91 }\n/* KeywordConstant */ .chroma .kc { color: #a90d91 }\n/* KeywordDeclaration */ .chroma .kd { color: #a90d91 }\n/* KeywordNamespace */ .chroma .kn { color: #a90d91 }\n/* KeywordPseudo */ .chroma .kp { color: #a90d91 }\n/* KeywordReserved */ .chroma .kr { color: #a90d91 }\n/* KeywordType */ .chroma .kt { color: #a90d91 }\n/* Name */ .chroma .n { color: #000000 }\n/* NameAttribute */ .chroma .na { color: #836c28 }\n/* NameBuiltin */ .chroma .nb { color: #a90d91 }\n/* NameBuiltinPseudo */ .chroma .bp { color: #5b269a }\n/* NameClass */ .chroma .nc { color: #3f6e75 }\n/* NameConstant */ .chroma .no { color: #000000 }\n/* NameDecorator */ .chroma .nd { color: #000000 }\n/* NameEntity */ .chroma .ni { color: #000000 }\n/* NameException */ .chroma .ne { color: #000000 }\n/* NameFunction */ .chroma .nf { color: #000000 }\n/* NameFunctionMagic */ .chroma .fm { color: #000000 }\n/* NameLabel */ .chroma .nl { color: #000000 }\n/* NameNamespace */ .chroma .nn { color: #000000 }\n/* NameOther */ .chroma .nx { color: #000000 }\n/* NameProperty */ .chroma .py { color: #000000 }\n/* NameTag */ .chroma .nt { color: #000000 }\n/* NameVariable */ .chroma .nv { color: #000000 }\n/* NameVariableClass */ .chroma .vc { color: #000000 }\n/* NameVariableGlobal */ .chroma .vg { color: #000000 }\n/* NameVariableInstance */ .chroma .vi { color: #000000 }\n/* NameVariableMagic */ .chroma .vm { color: #000000 }\n/* Literal */ .chroma .l { color: #1c01ce }\n/* LiteralDate */ .chroma .ld { color: #1c01ce }\n/* LiteralString */ .chroma .s { color: #c41a16 }\n/* LiteralStringAffix */ .chroma .sa { color: #c41a16 }\n/* LiteralStringBacktick */ .chroma .sb { color: #c41a16 }\n/* LiteralStringChar */ .chroma .sc { color: #2300ce }\n/* LiteralStringDelimiter */ .chroma .dl { color: #c41a16 }\n/* LiteralStringDoc */ .chroma .sd { color: #c41a16 }\n/* LiteralStringDouble */ .chroma .s2 { color: #c41a16 }\n/* LiteralStringEscape */ .chroma .se { color: #c41a16 }\n/* LiteralStringHeredoc */ .chroma .sh { color: #c41a16 }\n/* LiteralStringInterpol */ .chroma .si { color: #c41a16 }\n/* LiteralStringOther */ .chroma .sx { color: #c41a16 }\n/* LiteralStringRegex */ .chroma .sr { color: #c41a16 }\n/* LiteralStringSingle */ .chroma .s1 { color: #c41a16 }\n/* LiteralStringSymbol */ .chroma .ss { color: #c41a16 }\n/* LiteralNumber */ .chroma .m { color: #1c01ce }\n/* LiteralNumberBin */ .chroma .mb { color: #1c01ce }\n/* LiteralNumberFloat */ .chroma .mf { color: #1c01ce }\n/* LiteralNumberHex */ .chroma .mh { color: #1c01ce }\n/* LiteralNumberInteger */ .chroma .mi { color: #1c01ce }\n/* LiteralNumberIntegerLong */ .chroma .il { color: #1c01ce }\n/* LiteralNumberOct */ .chroma .mo { color: #1c01ce }\n/* Operator */ .chroma .o { color: #000000 }\n/* OperatorWord */ .chroma .ow { color: #000000 }\n/* Comment */ .chroma .c { color: #177500 }\n/* CommentHashbang */ .chroma .ch { color: #177500 }\n/* CommentMultiline */ .chroma .cm { color: #177500 }\n/* CommentSingle */ .chroma .c1 { color: #177500 }\n/* CommentSpecial */ .chroma .cs { color: #177500 }\n/* CommentPreproc */ .chroma .cp { color: #633820 }\n/* CommentPreprocFile */ .chroma .cpf { color: #633820 }\n</style><pre tabindex=\"0\" class=\"chroma\"><span class=\"n\">hello</span> <span class=\"n\">world</span><span class=\"o\">!</span></pre>';width:parent?parent.width:0;color:'#ECECEC';}";
    QString expe2 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);
    QCOMPARE(qmls[2], expe2);

    s = "file://1.mp4";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><div><a href='file://1.mp4'>file://1.mp4</a></div>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "a\n----\nb";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 1);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a<hr>b\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "# a\n----\n";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><h1>a</h1><hr>\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "----\nx";
    qmls = doc_parser->parseQML(s, 600);
    expe0 = "Txt{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style><hr>x\";width:parent?parent.width:0}";
    QCOMPARE(qmls[0], expe0);

    s = "```\na\n```\n```\nb\n```";
    qmls = doc_parser->parseQML(s, 600);
    Q_ASSERT(qmls.size() == 2);
    expe0 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>a\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    expe1 = "Quote{text:\"<style>*{margin:0;padding:0;}h1,h2,h3{color:black;}b{color:#303030;}</style>b\";width:parent?parent.width:0;color:'#303030';textColor:'#FFFFFF';}";
    QCOMPARE(qmls[0], expe0);
    QCOMPARE(qmls[1], expe1);

    // for(QString& qml:qmls) {
    //     qDebug() << qml;
    // }
}

void xxmoonTest::test18() {
    QString k = "#hello!(x)$";
    filterSearchKey(k);
    QCOMPARE(k, "#hellox");
    // qDebug() << k;
}

void xxmoonTest::test19() {
    QString s = "xxx\n```java\nxxxo world!\n```\naaa";
    QString k = "xx a";
    s = extractXMSimpleCont(s, k);
    QCOMPARE(s, "@#red xx@x\n```java\nxxxo world!\n```\n@#red a@aa");
}

void xxmoonTest::test20() {
    // a->initCfg();
    // Script::INS().exeCmd(1, "check_douyin_live.py", "");
    QProcess process;
    process.start("/usr/local/bin/python3", QStringList() << "/Volumes/MD/xxmoon/xxmoon/scripts/check_douyin_live.py");
    if(process.waitForStarted()) {
        if(process.waitForFinished()) {
            QString out = process.readAll();
            qDebug() << out;
        } else {
            qDebug() << process.errorString();
        }
    } else {
        qDebug() << process.errorString();
    }
}

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

    // int i = cont.lastIndexOf("\n----\n");
    // if(i >= 0) {
    //     cont = cont.mid(0, i);
    // }
    // qDebug() << cont;
}

QTEST_APPLESS_MAIN(xxmoonTest)

#include "tst_xxmoontest.moc"
