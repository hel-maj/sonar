/* ===== 23e3069f0 ui.main_window:? ===== */
/* ghidra_name=FUN_23e3069f0 entry=23e3069f0 size=2599 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e3069f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  code *pcVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined4 uVar17;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = _DAT_23eeafe88;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23eeafe88 == (longlong *)0x0) {
LAB_23e306a2e:
    _DAT_23eeafe88 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeac698,DAT_23eeac668,0x20);
  }
  else {
    lVar15 = *_DAT_23eeafe88;
    if (1 < lVar15) {
      *_DAT_23eeafe88 = lVar15 + -1;
      goto LAB_23e306a2e;
    }
    if (_DAT_23eeafe88[2] != 0) {
      *_DAT_23eeafe88 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e306a2e;
    }
  }
  plVar4 = _DAT_23eeafe88;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeafe88 + 9;
  lVar14 = *(longlong *)(lVar15 + 8);
  _DAT_23eeafe88[0xf] = lVar14;
  *(longlong **)(lVar15 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  lVar14 = DAT_23eeac660;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar15 = *(longlong *)(lVar14 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(lVar14,_DAT_23eeacac8);
    if (plVar10 == (longlong *)0x0) goto LAB_23e306e49;
    lVar14 = *plVar10;
LAB_23e307268:
    if (lVar14 == 0) goto LAB_23e306e49;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14db0 != iVar9) {
      _DAT_23ec14db0 = iVar9;
      _DAT_23eeafe78 = FUN_23e8cbd60(lVar15,_DAT_23eeacac8,*(undefined8 *)(_DAT_23eeacac8 + 0x18));
    }
    if (-1 < _DAT_23eeafe78) {
      lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeafe78 * 0x10);
      if (lVar14 != 0) goto LAB_23e306b1e;
      _DAT_23eeafe78 = FUN_23e8cbd60(lVar15,_DAT_23eeacac8,*(undefined8 *)(_DAT_23eeacac8 + 0x18));
      if (-1 < _DAT_23eeafe78) {
        lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eeafe78 * 0x10);
        goto LAB_23e307268;
      }
    }
LAB_23e306e49:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeacac8);
    if ((plVar10 == (longlong *)0x0) || (lVar14 = *plVar10, lVar14 == 0)) {
      plVar12 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eeacac8);
      uVar17 = 0xd2;
      uVar7 = uStack_60;
      plVar11 = plStack_58;
      uVar5 = uStack_68;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e30718a;
    }
  }
LAB_23e306b1e:
  *(undefined4 *)(plVar4 + 5) = 0xd2;
  plVar10 = (longlong *)FUN_23e914090(param_1,lVar14,plVar3);
  lVar15 = _DAT_23eeacad0;
  if (plVar10 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    plVar12 = (longlong *)0x0;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = 0xd2;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e30718a;
  }
  *(undefined4 *)(plVar4 + 5) = 0xd3;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeac910,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar17 = 0xd3;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e30718a;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeac9c0;
  *(undefined4 *)(plVar4 + 5) = 0xd4;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeacad8,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar17 = 0xd4;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e30718a;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = _DAT_23eeacae8;
  *(undefined4 *)(plVar4 + 5) = 0xd5;
  plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeacae0,*(undefined8 *)(lVar15 + 0x18))
  ;
  if (plVar11 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar17 = 0xd5;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e30718a;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  lVar15 = *(longlong *)(DAT_23eeac660 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeacaf0);
    if (plVar11 == (longlong *)0x0) goto LAB_23e3070a9;
    lVar15 = *plVar11;
LAB_23e307318:
    if (lVar15 == 0) goto LAB_23e3070a9;
  }
  else {
    iVar9 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec14e10;
      iVar9 = DAT_23ec14e10;
      DAT_23ec14e10 = DAT_23ec14e10 + 1;
    }
    if (_DAT_23ec14db4 != iVar9) {
      _DAT_23ec14db4 = iVar9;
      _DAT_23eeafe80 = FUN_23e8cbd60(lVar15,_DAT_23eeacaf0,*(undefined8 *)(_DAT_23eeacaf0 + 0x18));
    }
    if (-1 < _DAT_23eeafe80) {
      lVar14 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar14 + 8 + _DAT_23eeafe80 * 0x10) != 0) goto LAB_23e306c69;
      _DAT_23eeafe80 = FUN_23e8cbd60(lVar15,_DAT_23eeacaf0,*(undefined8 *)(_DAT_23eeacaf0 + 0x18));
      if (-1 < _DAT_23eeafe80) {
        lVar15 = *(longlong *)(lVar14 + 8 + _DAT_23eeafe80 * 0x10);
        goto LAB_23e307318;
      }
    }
LAB_23e3070a9:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeacaf0);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      plVar12 = (longlong *)0x0;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eeacaf0);
      uVar17 = 0xd7;
      uVar7 = uStack_60;
      plVar11 = plStack_58;
      uVar5 = uStack_68;
      plVar13 = DAT_23ed6a4f8;
      goto joined_r0x00023e30718a;
    }
  }
LAB_23e306c69:
  *(undefined4 *)(plVar4 + 5) = 0xd7;
  plVar12 = (longlong *)FUN_23e91a870(param_1);
  lVar15 = _DAT_23eeacb00;
  if (plVar12 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar17 = 0xd7;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar13 = DAT_23ed6a4f8;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0xd8;
    plVar11 = (longlong *)
              FUN_23e915840(param_1,plVar12,_DAT_23eeacaf8,*(undefined8 *)(lVar15 + 0x18));
    if (plVar11 == (longlong *)0x0) {
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      uVar17 = 0xd8;
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar7 = *(undefined8 *)(param_1 + 0x68);
      plVar13 = DAT_23ed6a4f8;
    }
    else {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *(undefined4 *)(plVar4 + 5) = 0xd9;
      plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eeacb08,plVar12);
      if (plVar11 == (longlong *)0x0) {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar17 = 0xd9;
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        plVar13 = DAT_23ed6a4f8;
      }
      else {
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eeac968);
        if (plVar11 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeacb10);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar13 != (longlong *)0x0) {
            *(undefined4 *)(plVar4 + 5) = 0xdb;
            plVar11 = (longlong *)FUN_23e914090(param_1,plVar13,plVar10);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar11 != (longlong *)0x0) {
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar4 = *(longlong **)(lVar15 + 0x28);
              plVar11 = (longlong *)plVar4[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
              *(undefined4 *)(plVar4 + 8) = 0xffffffff;
              if (plVar11 != (longlong *)0x0) {
                plVar4[2] = 0;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
              }
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))(plVar4);
              }
              lVar15 = *plVar10;
              plVar4[0xf] = 0;
              if (lVar15 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 == 0) {
                (**(code **)(plVar2[1] + 0x30))(plVar2);
              }
              *plVar3 = *plVar3 + -1;
              if (*plVar3 != 0) {
                return plVar10;
              }
              (**(code **)(plVar3[1] + 0x30))(plVar3);
              return plVar10;
            }
          }
        }
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar17 = 0xdb;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        plVar13 = DAT_23ed6a4f8;
      }
    }
  }
joined_r0x00023e30718a:
  DAT_23ed6a4f8 = plVar13;
  if (plVar11 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar15 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar17;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar14 = plVar13[-1];
    puVar6 = *(undefined8 **)(lVar15 + 8);
    *puVar6 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar16 = plVar13;
  }
  else {
    plVar16 = plVar11;
    if ((longlong *)plVar11[3] != plVar4) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar15 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar17;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
      lVar14 = plVar13[-1];
      puVar6 = *(undefined8 **)(lVar15 + 8);
      *puVar6 = plVar13 + -2;
      plVar13[-2] = lVar15;
      plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar6;
      lVar14 = *plVar11;
      *(longlong **)(lVar15 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar11;
      plVar16 = plVar13;
      if (lVar14 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b359,plVar2,plVar3,plVar10,plVar12);
  if (_DAT_23eeafe88 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeafe88 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar15 + 0x28);
  plVar11 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,uVar5,uVar7,plVar16);
  return (longlong *)0x0;
}
