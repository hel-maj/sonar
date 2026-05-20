/* ===== 23aab14c0 __main__:374 ===== */
/* ghidra_name=FUN_23aab14c0 entry=23aab14c0 size=4657 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_23aab14c0(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  undefined8 uVar6;
  longlong *plVar7;
  int iVar8;
  code *pcVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined8 uVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined4 uVar18;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar11 = _DAT_23ed90c20;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (_DAT_23ed90c20 == (longlong *)0x0) {
LAB_23aab1517:
    _DAT_23ed90c20 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90c18,DAT_23ed90d18,0x20);
  }
  else {
    lVar15 = *_DAT_23ed90c20;
    if (1 < lVar15) {
      *_DAT_23ed90c20 = lVar15 + -1;
      goto LAB_23aab1517;
    }
    if (_DAT_23ed90c20[2] != 0) {
      *_DAT_23ed90c20 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23aab1517;
    }
  }
  plVar3 = _DAT_23ed90c20;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23ed90c20 + 9;
  lVar10 = *(longlong *)(lVar15 + 8);
  _DAT_23ed90c20[0xf] = lVar10;
  *(longlong **)(lVar15 + 8) = plVar11;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((DAT_23ed6a210 == 0) &&
     (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec31700), DAT_23ed6a210 == 0)) {
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS","\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  pcVar4 = _Py_FalseStruct_exref;
  pcVar9 = (code *)FUN_23e8bbbe0(param_1,DAT_23ed6a210,_DAT_23ed8fb88,_Py_FalseStruct_exref);
  if (pcVar9 == (code *)0x0) {
    local_68 = *(longlong **)(param_1 + 0x70);
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar12 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    uVar18 = 0x17d;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23aab1943;
  }
  iVar8 = FUN_23a35f020(pcVar9);
  if (iVar8 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
    if (*(longlong *)pcVar9 == 0) {
      (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
    }
LAB_23aab1eae:
    uVar18 = 0x17d;
    plVar12 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    pcVar9 = (code *)0x0;
    goto LAB_23aab1943;
  }
  if (iVar8 != 1) {
    *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
    if (*(longlong *)pcVar9 == 0) {
      (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
    }
    iVar8 = PySequence_Contains(DAT_23ed8fb58,DAT_23ed6cdd0);
    if (iVar8 == -1) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aab1eae;
    }
    pcVar9 = pcVar4;
    if (iVar8 == 1) {
      pcVar9 = _Py_TrueStruct_exref;
    }
    *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
  }
  iVar8 = FUN_23a35f020(pcVar9);
  if (iVar8 == -1) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x17f;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23aab1943;
  }
  if (iVar8 == 0) {
    lVar10 = FUN_23ebc0cf0();
    lVar15 = _DAT_23ed900a0;
    if (lVar10 == 0) {
      plVar12 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      FUN_23e915740(param_1,local_78,DAT_23ed8fba8);
      uVar18 = 0x195;
      plVar11 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *(undefined4 *)(plVar3 + 5) = 0x195;
    plVar11 = (longlong *)FUN_23e915840(param_1,lVar10,DAT_23ed8fbb0,*(undefined8 *)(lVar15 + 0x18))
    ;
    if (plVar11 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x195;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar16 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
  }
  else {
    lVar15 = FUN_23ebc0a50();
    if (lVar15 == 0) {
      plVar12 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      FUN_23e915740(param_1,local_78,_DAT_23ed90040);
      uVar18 = 0x181;
      plVar11 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *(undefined4 *)(plVar3 + 5) = 0x181;
    plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar15,_DAT_23ed90048);
    if (plVar11 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x181;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aab1943;
    }
    iVar8 = FUN_23a35f020(plVar11);
    if (iVar8 == -1) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x183;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aab1943;
    }
    if (iVar8 != 0) {
      lVar15 = FUN_23ebc0cf0();
      if (lVar15 == 0) {
        plVar12 = (longlong *)0x0;
        FUN_23e915740(param_1,local_78,DAT_23ed8fba8);
        uVar18 = 0x184;
        plVar16 = (longlong *)0x0;
      }
      else {
        plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23ed90050);
        plVar12 = _DAT_23ed90058;
        if (plVar13 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          plVar16 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar18 = 0x184;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar12 = (longlong *)0x0;
        }
        else {
          lVar15 = *(longlong *)(param_1 + 0x10);
          plVar17 = *(longlong **)(lVar15 + 0xe20);
          if (plVar17 == (longlong *)0x0) {
            plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar10 = plVar17[3];
            *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
            *(longlong *)(lVar15 + 0xe20) = lVar10;
            *plVar17 = 1;
          }
          pcVar4 = _PyRuntime_exref;
          plVar17[4] = 0;
          lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
          lVar10 = plVar17[-1];
          puVar2 = *(undefined8 **)(lVar15 + 8);
          *puVar2 = plVar17 + -2;
          plVar17[-2] = lVar15;
          plVar17[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar15 + 8) = plVar17 + -2;
          uVar14 = _DAT_23ed90060;
          *plVar12 = *plVar12 + 1;
          plVar17[3] = (longlong)plVar12;
          lVar15 = PyUnicode_Join(uVar14,plVar11);
          if (lVar15 == 0) {
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar17 = *plVar17 + -1;
            plVar16 = (longlong *)0x0;
            if (*plVar17 == 0) {
              plVar12 = (longlong *)0x0;
              (**(code **)(plVar17[1] + 0x30))(plVar17);
              uVar18 = 0x184;
              goto LAB_23aab1943;
            }
          }
          else {
            plVar17[4] = lVar15;
            plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if (plVar12 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x184;
              plVar16 = (longlong *)FUN_23e914090(param_1,plVar13,plVar12);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar16 == (longlong *)0x0) {
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                plVar12 = (longlong *)0x0;
                plVar16 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar18 = 0x184;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar12 = (longlong *)0x0;
                plVar16 = (longlong *)0x0;
                uVar14 = FUN_23e91b0f0(param_1,*(undefined8 *)PyExc_SystemExit_exref,DAT_23ed6ccf0);
                local_78._0_8_ = uVar14;
                FUN_23e91b7d0(param_1,local_78);
                uVar18 = 0x187;
              }
              goto LAB_23aab1943;
            }
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            plVar16 = (longlong *)0x0;
            if (*plVar13 != 0) {
              plVar12 = (longlong *)0x0;
              uVar18 = 0x184;
              goto LAB_23aab1943;
            }
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          plVar16 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          uVar18 = 0x184;
        }
      }
      goto LAB_23aab1943;
    }
    plVar16 = (longlong *)
              FUN_23e93e1e0(FUN_23aab2770,_DAT_23ed90070,_DAT_23ed90078,_DAT_23ed90bf8,0,0,
                            DAT_23ed90d18,_DAT_23ed90068,0,0);
    lVar15 = FUN_23ebc0a50();
    if (lVar15 == 0) {
      FUN_23e915740(param_1,local_78,_DAT_23ed90040);
      uVar18 = 0x191;
      plVar12 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23ed90080);
    uVar14 = _DAT_23ed90088;
    if (plVar12 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0x191;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *(undefined4 *)(plVar3 + 5) = 0x191;
    uStack_80 = uVar14;
    local_88 = plVar16;
    plVar13 = (longlong *)FUN_23e9186b0(param_1,plVar12,&local_88,_DAT_23ed90090);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar12 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x191;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23aab1943;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    lVar10 = FUN_23ebc0cf0();
    lVar15 = _DAT_23ed90098;
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_78,DAT_23ed8fba8);
      uVar18 = 0x193;
      plVar12 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *(undefined4 *)(plVar3 + 5) = 0x193;
    plVar12 = (longlong *)FUN_23e915840(param_1,lVar10,DAT_23ed8fbb0,*(undefined8 *)(lVar15 + 0x18))
    ;
    if (plVar12 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0x193;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
  }
  lVar15 = *(longlong *)(DAT_23ed8fb58 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed900a8);
    if (plVar12 == (longlong *)0x0) goto LAB_23aab1fa0;
    lVar10 = *plVar12;
LAB_23aab1f94:
    if (lVar10 == 0) goto LAB_23aab1fa0;
  }
  else {
    iVar8 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec107d0;
      iVar8 = DAT_23ec107d0;
      DAT_23ec107d0 = DAT_23ec107d0 + 1;
    }
    if (_DAT_23ec1079c != iVar8) {
      _DAT_23ec1079c = iVar8;
      _DAT_23ed90c00 = FUN_23e8cbd60(lVar15,_DAT_23ed900a8,*(undefined8 *)(_DAT_23ed900a8 + 0x18));
    }
    if (-1 < _DAT_23ed90c00) {
      lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      lVar10 = *(longlong *)(lVar1 + 8 + _DAT_23ed90c00 * 0x10);
      if (lVar10 != 0) goto LAB_23aab170c;
      _DAT_23ed90c00 = FUN_23e8cbd60(lVar15,_DAT_23ed900a8,*(undefined8 *)(_DAT_23ed900a8 + 0x18));
      if (-1 < _DAT_23ed90c00) {
        lVar10 = *(longlong *)(lVar1 + 8 + _DAT_23ed90c00 * 0x10);
        goto LAB_23aab1f94;
      }
    }
LAB_23aab1fa0:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed900a8);
    if ((plVar12 == (longlong *)0x0) || (lVar10 = *plVar12, lVar10 == 0)) {
      plVar12 = (longlong *)0x0;
      FUN_23e915740(param_1,local_78,_DAT_23ed900a8);
      uVar18 = 0x19a;
      goto LAB_23aab1943;
    }
  }
LAB_23aab170c:
  plVar12 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed6cfe0);
  if (plVar12 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x19a;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    goto LAB_23aab1943;
  }
  lVar15 = *(longlong *)(DAT_23ed8fb58 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar13 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed900b0);
    if (plVar13 == (longlong *)0x0) goto LAB_23aab21f0;
    lVar15 = *plVar13;
LAB_23aab21e4:
    if (lVar15 == 0) goto LAB_23aab21f0;
  }
  else {
    iVar8 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec107d0;
      iVar8 = DAT_23ec107d0;
      DAT_23ec107d0 = DAT_23ec107d0 + 1;
    }
    if (_DAT_23ec107a0 != iVar8) {
      _DAT_23ec107a0 = iVar8;
      _DAT_23ed90c08 = FUN_23e8cbd60(lVar15,_DAT_23ed900b0,*(undefined8 *)(_DAT_23ed900b0 + 0x18));
    }
    if (-1 < _DAT_23ed90c08) {
      lVar10 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar10 + 8 + _DAT_23ed90c08 * 0x10) != 0) goto LAB_23aab179c;
      _DAT_23ed90c08 = FUN_23e8cbd60(lVar15,_DAT_23ed900b0,*(undefined8 *)(_DAT_23ed900b0 + 0x18));
      if (-1 < _DAT_23ed90c08) {
        lVar15 = *(longlong *)(lVar10 + 8 + _DAT_23ed90c08 * 0x10);
        goto LAB_23aab21e4;
      }
    }
LAB_23aab21f0:
    plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed900b0);
    if ((plVar13 == (longlong *)0x0) || (*plVar13 == 0)) {
      FUN_23e915740(param_1,local_78,_DAT_23ed900b0);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      uVar18 = 0x19a;
      plVar12 = (longlong *)0x0;
      goto LAB_23aab1943;
    }
  }
LAB_23aab179c:
  *(undefined4 *)(plVar3 + 5) = 0x19a;
  plVar13 = (longlong *)FUN_23e914090(param_1,plVar12);
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plVar13 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x19a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23aab1943;
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  lVar15 = *(longlong *)(DAT_23ed8fb58 + 0x20);
  if (*(char *)(lVar15 + 10) == '\0') {
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,_DAT_23ed900b8);
    if (plVar12 == (longlong *)0x0) goto LAB_23aab2300;
    lVar15 = *plVar12;
LAB_23aab22f2:
    if (lVar15 == 0) goto LAB_23aab2300;
  }
  else {
    iVar8 = *(int *)(lVar15 + 0xc);
    if (*(int *)(lVar15 + 0xc) == 0) {
      *(int *)(lVar15 + 0xc) = DAT_23ec107d0;
      iVar8 = DAT_23ec107d0;
      DAT_23ec107d0 = DAT_23ec107d0 + 1;
    }
    if (_DAT_23ec107a4 != iVar8) {
      _DAT_23ec107a4 = iVar8;
      _DAT_23ed90c10 = FUN_23e8cbd60(lVar15,_DAT_23ed900b8,*(undefined8 *)(_DAT_23ed900b8 + 0x18));
    }
    if (-1 < _DAT_23ed90c10) {
      lVar10 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
      if (*(longlong *)(lVar10 + 8 + _DAT_23ed90c10 * 0x10) != 0) goto LAB_23aab1852;
      _DAT_23ed90c10 = FUN_23e8cbd60(lVar15,_DAT_23ed900b8,*(undefined8 *)(_DAT_23ed900b8 + 0x18));
      if (-1 < _DAT_23ed90c10) {
        lVar15 = *(longlong *)(lVar10 + 8 + _DAT_23ed90c10 * 0x10);
        goto LAB_23aab22f2;
      }
    }
LAB_23aab2300:
    plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ed900b8);
    if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
      plVar12 = (longlong *)0x0;
      FUN_23e915740(param_1,local_78,_DAT_23ed900b8);
      uVar18 = 0x19c;
      goto LAB_23aab1943;
    }
  }
LAB_23aab1852:
  *(undefined4 *)(plVar3 + 5) = 0x19c;
  plVar12 = (longlong *)FUN_23e91a870(param_1);
  if (plVar12 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x19c;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x19d;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23ed900c0);
    if (plVar13 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0x19d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      uVar14 = FUN_23e91b0f0(param_1,*(undefined8 *)PyExc_SystemExit_exref,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      local_78._0_8_ = uVar14;
      FUN_23e91b7d0(param_1,local_78);
      uVar18 = 0x19d;
    }
  }
LAB_23aab1943:
  plVar17 = local_68;
  plVar13 = DAT_23ed6a4f8;
  if (local_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar15 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar18;
    lVar15 = *(longlong *)(lVar15 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(lVar15 + 0x2e8);
    lVar10 = plVar13[-1];
    puVar2 = *(undefined8 **)(lVar15 + 8);
    *puVar2 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar17 = plVar13;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))(local_68);
    }
  }
  else if ((longlong *)local_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar15 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar18;
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
    lVar10 = plVar13[-1];
    puVar2 = *(undefined8 **)(lVar15 + 8);
    *puVar2 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar13[2] = (longlong)plVar17;
    *plVar17 = *plVar17 + 1;
    plVar17 = plVar13;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))();
    }
  }
  local_68 = plVar17;
  FUN_23e8bba40(plVar3,&DAT_23ec31985,pcVar9,plVar11,plVar16,plVar12);
  if (_DAT_23ed90c20 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ed90c20 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar15 + 0x28);
  plVar13 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar13 = local_68;
  auVar5 = local_78;
  uVar14 = local_78._0_8_;
  uVar6 = local_78._8_8_;
  plVar3[0xf] = 0;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((pcVar9 != (code *)0x0) &&
     (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
    (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  local_78 = auVar5;
  local_68 = plVar13;
  FUN_23a33aa70(param_1,uVar14,uVar6,plVar13);
  return 0;
}
