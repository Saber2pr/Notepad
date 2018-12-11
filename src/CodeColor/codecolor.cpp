#include <QtGui>
#include "./codecolor.h"
#include"./src/vector/vectorhelper.hpp"

CodeColor::CodeColor(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    this->initCodeColor();
    this->setSingleLineCommentFormat();
    this->setFunctionFormat();
    this->setStringReferFormat();
}

void CodeColor::highlightBlock(const QString &text)
{
    foreach(const HighlightingRule &rule, this->highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while(index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index,length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    this->setMultiLineCommentFormat(text);
}

void CodeColor::setSingleLineCommentFormat(){
    QTextCharFormat singleLineCommentFormat;

    singleLineCommentFormat.setForeground(Qt::darkGreen);
    HighlightingRule singleLineCommentRule;
    singleLineCommentRule.pattern = QRegExp("//[^\n]*");
    singleLineCommentRule.format = singleLineCommentFormat;

    this->highlightingRules.push_back(singleLineCommentRule);
}

void CodeColor::setMultiLineCommentFormat(const QString &text){
    QRegExp commentStartExpression = QRegExp("/\\*");
    QRegExp commentEndExpression = QRegExp("\\*/");
    QTextCharFormat multiLineCommentFormat;

    multiLineCommentFormat.setForeground(Qt::darkGreen);

    int startIndex = 0;
    if (this->previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                    + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

void CodeColor::setFunctionFormat(){
    QTextCharFormat functionFormat;
    HighlightingRule funcRule;

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::darkBlue);

    funcRule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    funcRule.format = functionFormat;

    this->highlightingRules.push_back(funcRule);
}

void CodeColor::setStringReferFormat(){
    QTextCharFormat quotationFormat;
    HighlightingRule quotationRule;

    quotationFormat.setForeground(Qt::darkGreen);

    quotationRule.pattern = QRegExp("\".*\"");
    quotationRule.format = quotationFormat;

    this->highlightingRules.push_back(quotationRule);
}

void CodeColor::setTextQueue(const Keywords &keywordList)
{
    HighlightingRule rule;

    const QString tmp("\\b");
    foreach(const Keyword& keyword, keywordList)
    {
        QString pattern(tmp);
        pattern += keyword.word;
        pattern += tmp;
        rule.pattern = QRegExp(pattern);
        rule.format = keyword.format;

        this->highlightingRules.push_back(rule);
    }
}

CodeColor::Keywords CodeColor::createKeywords(const QStringList &words, const QBrush &brush){
    Keywords keywords;
    foreach(const QString& word, words){
        Keyword keyword;
        keyword.word = word;
        keyword.format.setForeground(brush);
        keywords.push_back(keyword);
    }
    return keywords;
}

void CodeColor::initCodeColor(){
    QStringList words;
    words << "var" << "let" << "const" << "break" << "typeof" << "case" << "switch" << "else"
          << "return" << "catch" << "for" << "while" << "function" << "throw" << "try" << "in"
          << "of" << "interface" << "import" << "export" << "public" << "private" << "class"
          << "extends" << "imlements" << "static" << "require" << "module" << "keyof" << "as"
          << "void" << "type";
    QStringList words_blue;
    words_blue << "new" << "this";

    CodeColor::Keywords keywords = CodeColor::createKeywords(words, Qt::darkMagenta);
    CodeColor::Keywords keywords_blue = CodeColor::createKeywords(words_blue, Qt::darkBlue);

    VectorHelper::merge(keywords, keywords_blue);

    this->setTextQueue(keywords);
}
