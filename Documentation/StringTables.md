# String Tables in Unreal Engine

This document summarizes our findings and best practices for using string tables in Unreal Engine to manage and localize UI text. String tables provide a centralized, maintainable way to handle localized strings, allowing you to support multiple languages and update text in one place.

## Overview

String tables are assets that store key-value pairs where keys identify a specific text string and values are the localized text. They help avoid hardcoding text throughout your code and Blueprints and simplify localization workflows.

## Benefits

- **Centralized Management:** All permanent UI text (e.g., "Connect", "Quit", etc.) is stored in one place.
- **Localization:** Supports multiple languages without changing the code. Only the string table asset (or its localized variants) needs to be updated.
- **Maintainability:** Changing text in a single string table asset propagates to all parts of the game that use the table.
- **Flexibility:** Easily integrated with both C++ and Blueprints.

## Setting Up String Tables

### In the Unreal Editor

1. **Create a String Table:**
   - In the Content Browser, right-click and choose **Miscellaneous > String Table**.
   - When prompted, choose a CSV or JSON format for easy editing, or create a new String Table asset.
   - Name the table (e.g., `ST_UIStrings`).

2. **Define Keys and Values:**
   - Open the string table asset.
   - Add entries for each piece of text. For example:
     - Key: `ConnectText` Value (String Source): `Connect`
     - Key: `QuitText`  Value (String Source): `Quit`
   - Repeat for all permanent UI texts.

3. **Localization Support:**
   - Use Unreal’s localization dashboard to create localized versions of the string table. This allows you to provide translations for different languages without modifying your code.

## Retrieving Strings in C++

### Using `FText::FromStringTable`

In your C++ code, you can retrieve localized text by referencing the string table and key:

```cpp
#include "Internationalization/Text.h"

// Retrieve a localized text using a key and table ID.
FText ConnectText = FText::FromStringTable(TEXT("ST_UIStrings"), TEXT("ConnectText"));
```

This function call retrieves the string associated with ConnectText in the ST_UIStrings table.
Note that the path for the table ID, ("ST_UIStrings") must be the complete object path from the Unreal Editor.  Locate the String Table asset, right click it, choose 'copy object path'.
We have moved the path to our PathAssets.h namsespace and now just include that header and use 'UIStrings' as the table id.

### Centralizing Text Retrieval
For ease of use and consistency, create a helper class (such as a Blueprint Function Library) to centralize all UI text retrieval:

```// MessagesFunctionLibrary.h

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MessagesFunctionLibrary.generated.h"

UCLASS()
class VIRTUE_API UMessagesFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "Config | UI")
    static FText GetConnectText()
    {
        return FText::FromStringTable(TEXT("ST_UIStrings"), TEXT("ConnectText"));
    }

    UFUNCTION(BlueprintPure, Category = "Config | UI")
    static FText GetQuitText()
    {
        return FText::FromStringTable(TEXT("ST_UIStrings"), TEXT("QuitText"));
    }

    // Add similar functions for other text strings...
};
```

Using this library throughout your code ensures that any changes to key names or table IDs can be managed in a single location.

## Using String Tables in Blueprints
Blueprint Function Library:
- You can call the functions in your MessagesFunctionLibrary directly from Blueprints, ensuring a consistent approach across both C++ and Blueprint code.

Direct Reference:
- In some cases, you may also choose to use the “From String Table” node in Blueprints if you need to dynamically look up a key.

## Best Practices
Centralize Your Text Retrieval:
- Always use a helper (like MessagesFunctionLibrary) to retrieve strings. This reduces duplication and centralizes changes.

Consistent Naming Conventions:
- Use clear, consistent key names that reflect their purpose (e.g., ConnectText, QuitText).

Use Localization Dashboard:
- Take full advantage of Unreal Engine’s localization dashboard to manage translations. Keep your string table updated with all UI text to ensure complete localization coverage.

Error Handling:
- Consider adding fallback logic in your helper functions in case a key is missing or a string table is not loaded.

Asset References:
- Use a consistent asset path or namespace when referencing your string table. This makes it easier to update the asset’s location or name in the future.

## Conclusion
Using string tables in Unreal Engine improves localization, centralizes UI text management, and simplifies the process of updating or adding new languages. By following the practices outlined in this document and using helper functions like those in MessagesFunctionLibrary, you can ensure that your project remains scalable and maintainable as it grows.
