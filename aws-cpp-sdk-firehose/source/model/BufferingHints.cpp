/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/firehose/model/BufferingHints.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Firehose::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

BufferingHints::BufferingHints() : 
    m_sizeInMBs(0),
    m_sizeInMBsHasBeenSet(false),
    m_intervalInSeconds(0),
    m_intervalInSecondsHasBeenSet(false)
{
}

BufferingHints::BufferingHints(const JsonValue& jsonValue) : 
    m_sizeInMBs(0),
    m_sizeInMBsHasBeenSet(false),
    m_intervalInSeconds(0),
    m_intervalInSecondsHasBeenSet(false)
{
  *this = jsonValue;
}

BufferingHints& BufferingHints::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("SizeInMBs"))
  {
    m_sizeInMBs = jsonValue.GetInteger("SizeInMBs");

    m_sizeInMBsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("IntervalInSeconds"))
  {
    m_intervalInSeconds = jsonValue.GetInteger("IntervalInSeconds");

    m_intervalInSecondsHasBeenSet = true;
  }

  return *this;
}

JsonValue BufferingHints::Jsonize() const
{
  JsonValue payload;

  if(m_sizeInMBsHasBeenSet)
  {
   payload.WithInteger("SizeInMBs", m_sizeInMBs);

  }

  if(m_intervalInSecondsHasBeenSet)
  {
   payload.WithInteger("IntervalInSeconds", m_intervalInSeconds);

  }

  return std::move(payload);
}