#ifndef CODECOLOR_H
#define CODECOLOR_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE
/**
 * @brief The CodeColor class
 */
class CodeColor : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    CodeColor(QTextDocument *parent = 0);
    /**
     * @brief The Keyword struct
     */
    struct Keyword{
        QString word;
        QTextCharFormat format;
    };
    /**
     * @brief Keywords
     */
    typedef std::vector<Keyword> Keywords;
    /**
     * @brief createKeywords
     * @param words
     * @param brush
     * @return
     */
    static Keywords createKeywords(const QStringList &words, const QBrush &brush = Qt::darkMagenta);
    /**
     * @brief setTextQueue
     * @param textQueue
     */
    void setTextQueue(const Keywords &keywordList);

protected:
    /**
     * @brief highlightBlock
     * @param text
     */
    void highlightBlock(const QString &text);

private:
    /**
     * @brief The HighlightingRule struct
     */
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    /**
     * @brief KeywordList
     */
    Keywords KeywordList;
    /**
     * @brief highlightingRules
     */
    std::vector<HighlightingRule> highlightingRules;
    /**
     * @brief setMultiLineCommentFormat
     * @param text
     */
    void setMultiLineCommentFormat(const QString &text);
    /**
     * @brief setSingleLineCommentFormat
     */
    void setSingleLineCommentFormat();
    /**
     * @brief setFunctionFormat
     */
    void setFunctionFormat();
    /**
     * @brief setStringReferFormat
     */
    void setStringReferFormat();
    /**
     * @brief initCodeColor
     */
    void initCodeColor();
};

#endif // CODECOLOR_H
