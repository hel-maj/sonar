/* ===== 23e1358d0 telegram.notification_manager:c549 ===== */
/* ghidra_name=FUN_23e1358d0 entry=23e1358d0 size=1163 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e1358d0(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uStack_58;
  undefined8 uStack_50;
  longlong *plStack_48;
  
  plVar6 = _DAT_23eeaad08;
  if (_DAT_23eeaad08 == (longlong *)0x0) {
LAB_23e135903:
    _DAT_23eeaad08 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaad00,DAT_23eeaae08,0);
  }
  else {
    lVar1 = *_DAT_23eeaad08;
    if (1 < lVar1) {
      *_DAT_23eeaad08 = lVar1 + -1;
      goto LAB_23e135903;
    }
    if (_DAT_23eeaad08[2] != 0) {
      *_DAT_23eeaad08 = lVar1 + -1;
      if (lVar1 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e135903;
    }
  }
  plVar3 = _DAT_23eeaad08;
  lVar1 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeaad08 + 9;
  lVar2 = *(longlong *)(lVar1 + 8);
  _DAT_23eeaad08[0xf] = lVar2;
  *(longlong **)(lVar1 + 8) = plVar6;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  lVar2 = DAT_23eea8118;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar1 = *(longlong *)(lVar2 + 0x20);
  if (*(char *)(lVar1 + 10) == '\0') {
    puVar5 = (undefined8 *)FUN_23a37a020(lVar2,DAT_23eea8368);
    if (puVar5 != (undefined8 *)0x0) {
      plVar6 = (longlong *)*puVar5;
LAB_23e135c58:
      if (plVar6 != (longlong *)0x0) goto LAB_23e1359f0;
    }
  }
  else {
    iVar4 = *(int *)(lVar1 + 0xc);
    if (*(int *)(lVar1 + 0xc) == 0) {
      *(int *)(lVar1 + 0xc) = DAT_23ec14c1c;
      iVar4 = DAT_23ec14c1c;
      DAT_23ec14c1c = DAT_23ec14c1c + 1;
    }
    if (_DAT_23ec14c14 != iVar4) {
      _DAT_23ec14c14 = iVar4;
      _DAT_23eeaacf8 = FUN_23e8cbd60(lVar1,DAT_23eea8368,*(undefined8 *)(DAT_23eea8368 + 0x18));
    }
    if (-1 < _DAT_23eeaacf8) {
      lVar2 = lVar1 + 0x20 + (1L << (*(byte *)(lVar1 + 9) & 0x3f));
      plVar6 = *(longlong **)(lVar2 + 8 + _DAT_23eeaacf8 * 0x10);
      if (plVar6 != (longlong *)0x0) goto LAB_23e1359f0;
      _DAT_23eeaacf8 = FUN_23e8cbd60(lVar1,DAT_23eea8368,*(undefined8 *)(DAT_23eea8368 + 0x18));
      if (-1 < _DAT_23eeaacf8) {
        plVar6 = *(longlong **)(lVar2 + 8 + _DAT_23eeaacf8 * 0x10);
        goto LAB_23e135c58;
      }
    }
  }
  puVar5 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8368);
  if ((puVar5 == (undefined8 *)0x0) || (plVar6 = (longlong *)*puVar5, plVar6 == (longlong *)0x0)) {
    FUN_23e915740(param_1,&uStack_58,DAT_23eea8368);
    plVar6 = DAT_23ed6a4f8;
    if (plStack_48 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar7 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar7;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar6[2] = 0;
      plVar6[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      plVar6[4] = 0xddffffffff;
      lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar6[-1];
      puVar5 = *(undefined8 **)(lVar1 + 8);
      *puVar5 = plVar6 + -2;
      plVar6[-2] = lVar1;
      plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar1 + 8) = plVar6 + -2;
      plVar7 = plVar6;
    }
    else {
      plVar7 = plStack_48;
      if ((longlong *)plStack_48[3] != plVar3) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar7 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar7;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        plVar6[3] = (longlong)plVar3;
        *plVar3 = *plVar3 + 1;
        plVar6[4] = 0xddffffffff;
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8)
        ;
        lVar2 = plVar6[-1];
        puVar5 = *(undefined8 **)(lVar1 + 8);
        *puVar5 = plVar6 + -2;
        plVar6[-2] = lVar1;
        plVar6[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
        lVar2 = *plStack_48;
        *(longlong **)(lVar1 + 8) = plVar6 + -2;
        plVar6[2] = (longlong)plStack_48;
        plVar7 = plVar6;
        if (lVar2 == 0) {
          (**(code **)(plStack_48[1] + 0x30))(plStack_48);
        }
      }
    }
    FUN_23e8bba40(plVar3,0);
    if (_DAT_23eeaad08 == plVar3) {
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      _DAT_23eeaad08 = (longlong *)0x0;
    }
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar6 = *(longlong **)(lVar1 + 0x28);
    plVar3 = (longlong *)plVar6[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar1 + 0x30);
    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
    if (plVar3 != (longlong *)0x0) {
      plVar6[2] = 0;
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))();
      }
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar6[0xf] = 0;
    FUN_23a33aa70(param_1,uStack_58,uStack_50,plVar7);
    return (longlong *)0x0;
  }
LAB_23e1359f0:
  lVar1 = *(longlong *)(param_1 + 0x38);
  *plVar6 = *plVar6 + 1;
  lVar2 = *(longlong *)(lVar1 + 8);
  plVar3 = *(longlong **)(lVar2 + 0x28);
  plVar7 = (longlong *)plVar3[2];
  *(undefined8 *)(lVar1 + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  return plVar6;
}
