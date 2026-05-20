/* ===== 23e125a00 telegram.handlers.screenshot_han:79 ===== */
/* ghidra_name=FUN_23e125a00 entry=23e125a00 size=2717 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e125a00(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  longlong *plStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar13 = DAT_23ed6a4e0;
  plVar2 = (longlong *)*param_3;
  lVar7 = param_3[1];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar12 = DAT_23ed6a4e0;
  }
  else {
    plVar12 = (longlong *)*DAT_23ed6a4e0;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    plVar8 = plVar12;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar8;
  }
  pcVar4 = _PyRuntime_exref;
  plVar13[2] = lVar7;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar13[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar13 + -2;
  plVar13[-2] = lVar7;
  plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar13 + -2;
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    DAT_23ed6a4e0 = (longlong *)*plVar12;
    *plVar12 = 1;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar4 = _PyRuntime_exref;
  plVar12[2] = 0;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar12[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar12 + -2;
  plVar12[-2] = lVar7;
  plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar12 + -2;
  uVar6 = FUN_23e8d7870(param_1,_DAT_23eea8948);
  uVar16 = DAT_23eeaaf50;
  *plVar13 = *plVar13 + 1;
  plStack_68 = plVar13;
  lVar7 = FUN_23e93e1e0(FUN_23e1264f0,_DAT_23eea8950,_DAT_23eea8958,_DAT_23eeaaee8,0,uVar6,uVar16,0,
                        &plStack_68,1);
  plVar8 = _DAT_23eeaaf10;
  plVar12[2] = lVar7;
  if (plVar8 == (longlong *)0x0) {
LAB_23e125b9c:
    plVar8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaaf08,DAT_23eeaaf50,0x20);
    _DAT_23eeaaf10 = plVar8;
  }
  else {
    lVar7 = *plVar8;
    if (1 < lVar7) {
      *plVar8 = lVar7 + -1;
      goto LAB_23e125b9c;
    }
    if (plVar8[2] != 0) {
      *plVar8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e125b9c;
    }
  }
  lVar7 = *(longlong *)(param_1 + 0x38);
  lVar14 = *(longlong *)(lVar7 + 8);
  plVar8[0xf] = lVar14;
  *(longlong **)(lVar7 + 8) = plVar8 + 9;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  uVar16 = _DAT_23eea8960;
  *(undefined4 *)(plVar8 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,uVar16);
  if (plVar9 == (longlong *)0x0) {
LAB_23e126050:
    plStack_70 = *(longlong **)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x57;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar16 = *(undefined8 *)(param_1 + 0x68);
    plVar11 = DAT_23ed6a4f8;
  }
  else {
    lVar7 = *(longlong *)(DAT_23eea87c8 + 0x20);
    if (*(char *)(lVar7 + 10) == '\0') {
      plVar10 = (longlong *)FUN_23a37a020(DAT_23eea87c8,DAT_23eea8968);
      if (plVar10 == (longlong *)0x0) goto LAB_23e125fc9;
      lVar14 = *plVar10;
LAB_23e126408:
      if (lVar14 == 0) goto LAB_23e125fc9;
LAB_23e125cb3:
      plVar10 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eea8970);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea8978);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar8 + 5) = 0x57;
          plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar11,_DAT_23eea8980);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar10 != (longlong *)0x0) {
            *(undefined4 *)(plVar8 + 5) = 0x57;
            plVar11 = (longlong *)FUN_23e914090(param_1,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            uVar16 = _DAT_23eea8988;
            if (plVar11 == (longlong *)0x0) goto LAB_23e126050;
            lVar7 = *(longlong *)(DAT_23eea87c8 + 0x20);
            if (*(char *)(lVar7 + 10) == '\0') {
              plVar9 = (longlong *)FUN_23a37a020(DAT_23eea87c8,DAT_23eea8990);
              if (plVar9 == (longlong *)0x0) goto LAB_23e126341;
              lVar14 = *plVar9;
LAB_23e126488:
              if (lVar14 == 0) goto LAB_23e126341;
            }
            else {
              iVar5 = *(int *)(lVar7 + 0xc);
              if (*(int *)(lVar7 + 0xc) == 0) {
                *(int *)(lVar7 + 0xc) = _DAT_23ec14c50;
                iVar5 = _DAT_23ec14c50;
                _DAT_23ec14c50 = _DAT_23ec14c50 + 1;
              }
              if (_DAT_23ec14c48 != iVar5) {
                _DAT_23ec14c48 = iVar5;
                _DAT_23eeaaef8 =
                     FUN_23e8cbd60(lVar7,DAT_23eea8990,*(undefined8 *)(DAT_23eea8990 + 0x18));
              }
              if (-1 < _DAT_23eeaaef8) {
                lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
                lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeaaef8 * 0x10);
                if (lVar14 != 0) goto LAB_23e125dff;
                _DAT_23eeaaef8 =
                     FUN_23e8cbd60(lVar7,DAT_23eea8990,*(undefined8 *)(DAT_23eea8990 + 0x18));
                if (-1 < _DAT_23eeaaef8) {
                  lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeaaef8 * 0x10);
                  goto LAB_23e126488;
                }
              }
LAB_23e126341:
              plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8990);
              if ((plVar9 == (longlong *)0x0) || (lVar14 = *plVar9, lVar14 == 0)) {
                FUN_23e915740(param_1,&plStack_68,DAT_23eea8990);
                plStack_70 = plStack_68;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                uVar15 = 0x58;
                plVar10 = plStack_58;
                uVar16 = uStack_60;
                plVar11 = DAT_23ed6a4f8;
                goto joined_r0x00023e12607a;
              }
            }
LAB_23e125dff:
            uVar6 = _PyDict_NewPresized(2);
            PyDict_SetItem(uVar6,uVar16,lVar14);
            pcVar4 = _Py_NoneStruct_exref;
            PyDict_SetItem(uVar6,_DAT_23eea8998,_Py_NoneStruct_exref);
            uVar16 = _DAT_23eea89a0;
            *plVar12 = *plVar12 + 1;
            plStack_68 = plVar12;
            plVar9 = (longlong *)
                     FUN_23e93e1e0(FUN_23e126b20,_DAT_23eea89a8,_DAT_23eea89b0,_DAT_23eeaaf00,0,
                                   uVar6,DAT_23eeaaf50,uVar16,&plStack_68,1);
            *(undefined4 *)(plVar8 + 5) = 0x57;
            plVar10 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar10 != (longlong *)0x0) {
              lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar8 = *(longlong **)(lVar7 + 0x28);
              plVar9 = (longlong *)plVar8[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
              *(undefined4 *)(plVar8 + 8) = 0xffffffff;
              if (plVar9 != (longlong *)0x0) {
                plVar8[2] = 0;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *(longlong *)pcVar4 = *(longlong *)pcVar4 + 1;
              plVar8[0xf] = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar7 = *plVar2;
              *plVar2 = lVar7 + -1;
              if (lVar7 + -1 != 0) {
                return pcVar4;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return pcVar4;
            }
            goto LAB_23e126050;
          }
        }
      }
      plStack_70 = *(longlong **)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar16 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      iVar5 = *(int *)(lVar7 + 0xc);
      if (*(int *)(lVar7 + 0xc) == 0) {
        *(int *)(lVar7 + 0xc) = _DAT_23ec14c50;
        iVar5 = _DAT_23ec14c50;
        _DAT_23ec14c50 = _DAT_23ec14c50 + 1;
      }
      if (_DAT_23ec14c44 != iVar5) {
        _DAT_23ec14c44 = iVar5;
        _DAT_23eeaaef0 = FUN_23e8cbd60(lVar7,DAT_23eea8968,*(undefined8 *)(DAT_23eea8968 + 0x18));
      }
      if (-1 < _DAT_23eeaaef0) {
        lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
        lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeaaef0 * 0x10);
        if (lVar14 != 0) goto LAB_23e125cb3;
        _DAT_23eeaaef0 = FUN_23e8cbd60(lVar7,DAT_23eea8968,*(undefined8 *)(DAT_23eea8968 + 0x18));
        if (-1 < _DAT_23eeaaef0) {
          lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeaaef0 * 0x10);
          goto LAB_23e126408;
        }
      }
LAB_23e125fc9:
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8968);
      if ((plVar10 != (longlong *)0x0) && (lVar14 = *plVar10, lVar14 != 0)) goto LAB_23e125cb3;
      FUN_23e915740(param_1,&plStack_68,DAT_23eea8968);
      plStack_70 = plStack_68;
      plVar10 = plStack_58;
      uVar16 = uStack_60;
    }
    *plVar9 = *plVar9 + -1;
    uVar15 = 0x57;
    plVar11 = DAT_23ed6a4f8;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar15 = 0x57;
      plVar11 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e12607a:
  DAT_23ed6a4f8 = plVar11;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar7 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar14 = plVar11[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
    plVar9 = plVar11;
  }
  else {
    plVar9 = plVar10;
    if ((longlong *)plVar10[3] != plVar8) {
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar4 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar8;
      *plVar8 = *plVar8 + 1;
      lVar7 = *(longlong *)(pcVar4 + 0x1f8);
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar14 = plVar11[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
      lVar14 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar10;
      plVar9 = plVar11;
      if (lVar14 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar8,&DAT_23ec5a38a,plVar2,plVar13,plVar12,0);
  if (_DAT_23eeaaf10 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eeaaf10 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar10 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  lVar7 = *plVar2;
  *plVar2 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plStack_70,uVar16,plVar9);
  return (code *)0x0;
}
