/* ===== 23e12da40 telegram.notification_manager:34 ===== */
/* ghidra_name=FUN_23e12da40 entry=23e12da40 size=1664 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e12da40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  code *pcVar11;
  int iVar12;
  undefined4 uVar13;
  longlong *plVar14;
  undefined8 uVar15;
  undefined8 uStack_78;
  longlong *plStack_68;
  code *pcStack_60;
  
  plVar6 = _DAT_23eeaade0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeaade0 != (longlong *)0x0) {
    lVar10 = *_DAT_23eeaade0;
    if (lVar10 < 2) {
      if (_DAT_23eeaade0[2] == 0) goto LAB_23e12daa9;
      *_DAT_23eeaade0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
    }
    else {
      *_DAT_23eeaade0 = lVar10 + -1;
    }
  }
  _DAT_23eeaade0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaadd8,DAT_23eeaae08,0x20);
LAB_23e12daa9:
  plVar4 = _DAT_23eeaade0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeaade0 + 9;
  lVar3 = *(longlong *)(lVar10 + 8);
  _DAT_23eeaade0[0xf] = lVar3;
  *(longlong **)(lVar10 + 8) = plVar6;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar15 = DAT_23eea8128;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,uVar15);
  if (plVar6 == (longlong *)0x0) {
    uStack_78 = *(undefined8 *)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    plVar7 = (longlong *)0x0;
    uVar13 = 0x24;
    plVar6 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0x24;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23eea8170);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if (plVar7 == (longlong *)0x0) {
      uStack_78 = *(undefined8 *)(param_1 + 0x60);
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      plVar9 = (longlong *)0x0;
      uVar13 = 0x24;
      plVar6 = *(longlong **)(param_1 + 0x70);
    }
    else {
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
      plVar6 = _DAT_23eea8178;
      lVar10 = DAT_23ed6cce8;
      if (plVar8 == (longlong *)0x0) {
        uStack_78 = *(undefined8 *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = (longlong *)0x0;
        uVar13 = 0x25;
        plVar6 = *(longlong **)(param_1 + 0x70);
      }
      else {
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        iVar12 = *(int *)(lVar3 + 0x1410);
        *plVar9 = *plVar9 + 1;
        if (iVar12 == 0) {
          pcVar11 = (code *)FUN_23a33a530(PyDict_Type_exref);
          plVar9 = *(longlong **)(lVar10 + 0x20);
        }
        else {
          iVar12 = iVar12 + -1;
          *(int *)(lVar3 + 0x1410) = iVar12;
          pcVar11 = *(code **)(lVar3 + 0x1190 + (longlong)iVar12 * 8);
          *(longlong *)pcVar11 = 1;
        }
        lVar10 = *(longlong *)(lVar10 + 0x28);
        *(longlong *)(pcVar11 + 0x10) = 0;
        *(longlong **)(pcVar11 + 0x20) = plVar9;
        *(longlong *)(pcVar11 + 0x28) = lVar10;
        *(longlong *)(pcVar11 + 0x18) = 1;
        *(undefined4 *)(plVar4 + 5) = 0x25;
        plStack_68 = plVar6;
        pcStack_60 = pcVar11;
        plVar9 = (longlong *)FUN_23e94ed00(param_1,pcVar11,&plStack_68);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
        if (*(longlong *)pcVar11 == 0) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
        if (plVar9 == (longlong *)0x0) {
          uStack_78 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x25;
          plVar6 = *(longlong **)(param_1 + 0x70);
        }
        else {
          plVar6 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ed6ce40);
          if (plVar6 != (longlong *)0x0) {
            *(undefined4 *)(plVar4 + 5) = 0x26;
            pcStack_60 = _Py_FalseStruct_exref;
            plStack_68 = plVar2;
            lVar10 = FUN_23e94ed00(param_1,plVar6,&plStack_68);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (lVar10 != 0) {
              lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar6 = *(longlong **)(lVar3 + 0x28);
              plVar4 = (longlong *)plVar6[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
              *(undefined4 *)(plVar6 + 8) = 0xffffffff;
              if (plVar4 != (longlong *)0x0) {
                plVar6[2] = 0;
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
              }
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar6[0xf] = 0;
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 != 0) {
                return lVar10;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return lVar10;
            }
          }
          uStack_78 = *(undefined8 *)(param_1 + 0x60);
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = 0x26;
          plVar6 = *(longlong **)(param_1 + 0x70);
        }
      }
    }
  }
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = DAT_23ed6a4f8;
  if (plVar6 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar10 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar3 = plVar8[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar8 + -2;
    plVar8[-2] = lVar10;
    plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar8 + -2;
    plVar14 = plVar8;
  }
  else {
    plVar14 = plVar6;
    if ((longlong *)plVar6[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar11 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar10 = *(longlong *)(pcVar11 + 0x1f8);
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar3 = plVar8[-1];
      puVar5 = *(undefined8 **)(lVar10 + 8);
      *puVar5 = plVar8 + -2;
      plVar8[-2] = lVar10;
      plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar6;
      *(longlong **)(lVar10 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar6;
      plVar14 = plVar8;
      if (lVar3 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5a149,plVar1,plVar2,plVar7,plVar9);
  if (_DAT_23eeaade0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeaade0 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar10 + 0x28);
  plVar4 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uStack_78,uVar15,plVar14);
  return 0;
}
